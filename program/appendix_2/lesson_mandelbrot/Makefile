CFLAGS =
CFLAGS += -mcmodel=medany
CFLAGS += -static
CFLAGS += -std=gnu99
CFLAGS += -O2
CFLAGS += -ffast-math
# CFLAGS += -fno-common
# CFLAGS += -fno-builtin-printf
CFLAGS += -static
# CFLAGS += -nostdlib
# CFLAGS += -nostartfiles
CFLAGS += -lm
CFLAGS += -lgcc
# CFLAGS += -T ./link.ld

CLANG 	= ../../../../llvm-myriscvx100-2nd/build/bin/clang
LLC   	= ../../../../llvm-myriscvx100-2nd/build/bin/llc
DUMP  	= ../../../../llvm-myriscvx100-2nd/build/bin/llvm-dis
MC    	= ../../../../llvm-myriscvx100-2nd/build/bin/llvm-mc
OBJDUMP = ../../../../llvm-myriscvx100-2nd/build/bin/llvm-objdump

COMMON_OPTIONS =
COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O3
CLANG64_OPTIONS += --target=riscv64-unknown-elf

.PHONY: mandelbrot_riscv_run mandelbrot_llvm_run mandelbrot_x86_run

all: mandelbrot_riscv_run mandelbrot_llvm_run mandelbrot_x86_run

mandelbrot_x86_run: mandelbrot.x86
	./$^ > mandelbrot_x86.pgm

mandelbrot.x86: mandelbrot.c mandelbrot_main.c mandelbrot.h
	gcc $^ -lm -o $@

mandelbrot_riscv_run: mandelbrot.riscv
	spike pk $^ > mandelbrot_riscv.pgm

mandelbrot_llvm_run: mandelbrot.llvm.riscv
	spike pk $^ > mandelbrot_myriscvx.pgm

mandelbrot.riscv: mandelbrot.c mandelbrot_main.c # syscalls.c crt.S
	riscv64-unknown-elf-gcc -o $@ $^ $(CFLAGS)

mandelbrot.llvm.riscv: mandelbrot.myriscvx64.static.S mandelbrot_main.riscv.o # syscalls.c crt.S
	riscv64-unknown-elf-gcc -o $@ $^ $(CFLAGS)

mandelbrot.myriscvx64.static.medany.S: mandelbrot.riscv64.bc
	$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $< -o $@ > $@.log 2>&1

mandelbrot.myriscvx64.static.S: mandelbrot.riscv64.bc
	$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static -filetype=asm $< -o $@ > $@.log 2>&1

mandelbrot.riscv64.static.S: mandelbrot.riscv64.bc
	$(LLC) -march=riscv64 -mattr=FD $(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $< -o $@ > $@.log 2>&1

mandelbrot.riscv64.bc: mandelbrot.c
	$(CLANG) $(CLANG64_OPTIONS) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

mandelbrot_main.riscv.o: mandelbrot_main.c Makefile
	riscv64-unknown-elf-gcc $< -o $@ -c $(CFLAGS)

include ../../common.mk
