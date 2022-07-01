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

CLANG 	= ../../../../llvm-myriscvx120-fp/build/bin/clang
LLC   	= ../../../../llvm-myriscvx120-fp/build/bin/llc
DUMP  	= ../../../../llvm-myriscvx120-fp/build/bin/llvm-dis
MC    	= ../../../../llvm-myriscvx120-fp/build/bin/llvm-mc
OBJDUMP = ../../../../llvm-myriscvx120-fp/build/bin/llvm-objdump

COMMON_OPTIONS =
COMMON_OPTIONS += -disable-tail-calls

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O3
# CLANG64_OPTIONS += --target=riscv64-unknown-elf

TARGET=raytracer

.PHONY: mandelbrot_llvm

all: $(TARGET) $(TARGET).riscv $(TARGET).llvm.riscv
	spike pk $(TARGET).llvm.riscv > $(TARGET).llvm.riscv.ppm

$(TARGET).riscv: $(TARGET).cpp  # syscalls.c crt.S
	riscv64-unknown-elf-g++ -o $@ $^ $(CFLAGS)

$(TARGET).llvm.riscv: $(TARGET).myriscvx64.static.S # syscalls.c crt.S
	riscv64-unknown-elf-g++ -o $@ $^ $(CFLAGS)

$(TARGET)_llvm: $(TARGET).myriscvx64.static.medany.S $(TARGET)_main.myriscvx64.static.medany.S

$(TARGET).myriscvx64.static.medany.S: $(TARGET).riscv64.bc
	$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $< -o $@ > $@.log 2>&1

$(TARGET).myriscvx64.static.S: $(TARGET).riscv64.bc
	$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static -filetype=asm $< -o $@ > $@.log 2>&1

$(TARGET).riscv64.static.S: $(TARGET).riscv64.bc
	$(LLC) -march=riscv64 -mattr=FD $(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $< -o $@ > $@.log 2>&1

$(TARGET).riscv64.bc: $(TARGET).cpp
	$(CLANG) $(CLANG64_OPTIONS) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

$(TARGET)_main.riscv.o: $(TARGET)_main.c Makefile
	riscv64-unknown-elf-gcc $< -o $@ -c $(CFLAGS)

include ../../common.mk
