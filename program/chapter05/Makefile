.PHONY: constants
all: constants

CLANG = ../../../llvm-myriscvx80/build/bin/clang
LLC   = ../../../llvm-myriscvx80/build/bin/llc
DUMP  = ../../../llvm-myriscvx80/build/bin/llvm-dis

constants: constants.myriscvx32.S constants.riscv32.S

constants.myriscvx32.S: constants.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log

constants2.myriscvx32.S: constants2.ll Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log

constants.riscv32.S: constants.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm $< -o $@ 2>&1 | tee $@.riscv32.log

constants.bc: constants.c Makefile
	$(CLANG) $< -c -emit-llvm -O3 -o $@
	$(DUMP) $@ -o $@.ll

isel.myriscvx32.S: constants_test.ll Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -view-dag-combine1-dags $< -o $@ 2>&1 | tee $@.isel.debug.log

isel.riscv32.S: constants_test.ll Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm $< -o $@ 2>&1 | tee $@.isel.debug.log

simple.bc: simple.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@

clean:
	$(RM) *.bc *.S *.bc.ll *.log *.dump
