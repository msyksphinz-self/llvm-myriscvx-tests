all: riscv_test

CLEAN += riscv_test

include $(realpath ../common.mk ../../common.mk)

riscv_test: riscv_test.c
	$(CLANG) $@.c -emit-llvm -c --target=riscv64-unknown-elf
	$(LLC) $@.bc -march=riscv64 -mattr="+d,+f" -filetype=asm
	riscv64-unknown-elf-gcc riscv_test.s -march=rv64gc -lc -o $@
