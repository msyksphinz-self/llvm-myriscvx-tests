.PHONY: constants arithmetics rotate_test
all: constants arithmetics compare_slt rotate_test

CLANG = ../../../llvm-myriscvx80/build/bin/clang
LLC   = ../../../llvm-myriscvx80/build/bin/llc
DUMP  = ../../../llvm-myriscvx80/build/bin/llvm-dis

func_arguments.o: func_arguments.c Makefile
	riscv32-unknown-elf-gcc -O0 $< -c -o $@
	riscv32-unknown-elf-objdump -d $@ > $@.dmp

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
	$(DUMP) $@ -o $@.ll

simple.myriscvx32.S: simple.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log

csi_test.bc: csi_test.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

arithmetics: arithmetics.myriscvx32.S arithmetics.myriscvx64.S
arithmetics.bc: arithmetics.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll
arithmetics.myriscvx32.S: arithmetics.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log
arithmetics.myriscvx64.S: arithmetics.bc Makefile
	$(LLC) -debug -march=myriscvx64 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx64.log


compare_slt: compare_slt.myriscvx32.S compare_slt.myriscvx64.S
compare_slt.bc: compare_slt.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll
compare_slt.myriscvx32.S: compare_slt.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log
compare_slt.myriscvx64.S: compare_slt.bc Makefile
	$(LLC) -debug -march=myriscvx64 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx64.log

rotate_test: rotate_test.myriscvx32.S rotate_test.myriscvx64.S
rotate_test.bc: rotate_test.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll
rotate_test.myriscvx32.S: rotate_test.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx32.log
rotate_test.myriscvx64.S: rotate_test.bc Makefile
	$(LLC) -debug -march=myriscvx64 -filetype=asm $< -o $@ 2>&1 | tee $@.myriscvx64.log


clean:
	$(RM) *.bc *.S *.bc.ll *.log *.dump
