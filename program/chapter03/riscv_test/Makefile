all: riscv_test

include $(realpath ../common.mk ../../common.mk)

riscv_test: riscv_test.c
	$(CLANG) $@ -emit-llvm -c
	$(LLVM_DIS) $@.bc
	$(LLC) $@.bc -filetype=asm
	riscv64-unknown-elf-gcc riscv_test.s -lc -o $@
