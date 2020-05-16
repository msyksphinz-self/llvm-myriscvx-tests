TARGET = simple_sort

.PHONY: all test

CLANG = ../../../../llvm-myriscvx100/build/bin/clang
LLC   = ../../../../llvm-myriscvx100/build/bin/llc
DUMP  = ../../../../llvm-myriscvx100/build/bin/llvm-dis


# CLANG_OPTIONS += -O3

all: test test_$(TARGET).static.riscv

test: $(TARGET).myriscvx32.static.medlow.S $(TARGET).myriscvx64.static.medlow.S \
	$(TARGET).myriscvx32.static.medany.S $(TARGET).myriscvx32.static.medlow.S


test_$(TARGET).static.riscv: test_$(TARGET).c $(TARGET).myriscvx64.static.medany.S crt.S syscalls.c
	riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	riscv64-unknown-elf-objdump -D $@ > $@.dmp

$(TARGET).myriscvx32.static.medlow.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $(TARGET).myriscvx32.static.medlow.S $(TARGET).riscv.static.bc		> $(TARGET).myriscvx32.static.asm.log 2>&1
$(TARGET).myriscvx64.static.medlow.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $(TARGET).myriscvx64.static.medlow.S $(TARGET).riscv.static.bc		> $(TARGET).myriscvx64.static.asm.log 2>&1

$(TARGET).myriscvx32.static.medany.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $(TARGET).myriscvx32.static.medany.S $(TARGET).riscv.static.bc		> $(TARGET).myriscvx32.static.asm.log 2>&1
$(TARGET).myriscvx64.static.medany.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $(TARGET).myriscvx64.static.medany.S $(TARGET).riscv.static.bc		> $(TARGET).myriscvx64.static.asm.log 2>&1

$(TARGET).riscv32.static.medany.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=riscv32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $(TARGET).riscv32.static.medany.S $(TARGET).riscv.static.bc		> $(TARGET).riscv32.static.asm.log 2>&1
$(TARGET).riscv64.static.medany.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=riscv64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $(TARGET).riscv64.static.medany.S $(TARGET).riscv.static.bc		> $(TARGET).riscv64.static.asm.log 2>&1

$(TARGET).riscv.static.bc: $(TARGET).c Makefile
	$(CLANG) $(CLANG_OPTIONS) $(TARGET).c -c -target riscv64-unknown-elf -emit-llvm  -o $(TARGET).riscv.static.bc
	$(DUMP) $(TARGET).riscv.static.bc -o $(TARGET).riscv.static.bc.ll

$(TARGET).riscv.pic.bc: $(TARGET).c Makefile
	$(CLANG) $(CLANG_OPTIONS) $(TARGET).c -c -fpic -target riscv64-unknown-elf -emit-llvm  -o $(TARGET).riscv.static.bc
	$(DUMP) $(TARGET).riscv.static.bc -o $(TARGET).riscv.static.bc.ll


include ../../common.mk
