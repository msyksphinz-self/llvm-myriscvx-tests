TARGET = gcd.riscv

all: gcd.riscv gcd.nopk.riscv

gcd.riscv: gcd.c Makefile
	riscv64-unknown-elf-gcc -O2 $< -o $@
	riscv64-unknown-elf-objdump -d gcd.riscv > gcd.dmp


gcd.nopk.riscv: gcd.c Makefile
	riscv64-unknown-elf-gcc -static -mcmodel=medany -fno-common \
		-fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc -T link.ld \
		syscalls.c crt.S \
		$< -o $@
	riscv64-unknown-elf-objdump -D $@ > $@.dmp
