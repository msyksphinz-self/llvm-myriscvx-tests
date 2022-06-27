TARGET = cond_if

CODE_MODEL=medium
# CODE_MODEL=small
ifeq ($(CODE_MODEL),medium)
  GCC_CMODEL=medany
else
  GCC_CMODEL=medlow
endif

CLANG = ../../../../llvm-myriscvx100/build/bin/clang
LLC   = ../../../../llvm-myriscvx100/build/bin/llc
DUMP  = ../../../../llvm-myriscvx100/build/bin/llvm-dis

# CLANG_OPTIONS += -O3

all: test_$(TARGET).riscv

test_$(TARGET).riscv: test_$(TARGET).c $(TARGET).myriscvx64.static.$(GCC_CMODEL).S crt.S syscalls.c
	riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -mcmodel=medany -static -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	riscv64-unknown-elf-objdump -D $@ > $@.dmp

$(TARGET).myriscvx32.static.medlow.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=small -filetype=asm -o $@ $< > $(TARGET).myriscvx32.static.asm.log 2>&1
$(TARGET).myriscvx64.static.medlow.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=small -filetype=asm -o $@ $< > $(TARGET).myriscvx64.static.asm.log 2>&1

$(TARGET).myriscvx32.static.medany.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $@ $< > $(TARGET).myriscvx32.static.asm.log 2>&1
$(TARGET).myriscvx64.static.medany.S: $(TARGET).riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $@ $< > $(TARGET).myriscvx64.static.asm.log 2>&1

$(TARGET).riscv.static.bc: $(TARGET).c Makefile
	$(CLANG) $(CLANG_OPTIONS) $(TARGET).c -c -target riscv64-unknown-elf -emit-llvm  -o $(TARGET).riscv.static.bc
	$(DUMP) $(TARGET).riscv.static.bc -o $(TARGET).riscv.static.bc.ll


include ../../common.mk
