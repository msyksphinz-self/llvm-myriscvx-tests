.PHONY: constants
all: constants

CLANG = ../../build/bin/clang
LLC = ../../build/bin/llc
DUMP = ../../build/bin/llvm-dis

constants: constants.myriscvx32.S constants.riscv32.S

constants.myriscvx32.S: constants.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log

constants.riscv32.S: constants.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm $< -o $@ 2>&1 | tee $@.riscv32.log

constants.bc: constants.c Makefile
	$(CLANG) $< -c -emit-llvm -O3 -o $@
	$(DUMP) $@ -o $@.ll

clean:
	$(RM) *.bc *.S *.ll *.log *.dump
