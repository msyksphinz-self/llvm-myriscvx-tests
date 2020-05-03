CLANG = ../../../../llvm-myriscvx100/build/bin/clang
LLC   = ../../../../llvm-myriscvx100/build/bin/llc
DUMP  = ../../../../llvm-myriscvx100/build/bin/llvm-dis


all: test_simple_pattern_match.riscv

test_simple_pattern_match.riscv: test_simple_pattern_match.c simple_pattern_match.myriscvx64.S crt.S syscalls.c
	riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -mcmodel=medany -static -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	riscv64-unknown-elf-objdump -D $@ > $@.dmp

include ../Makefile
