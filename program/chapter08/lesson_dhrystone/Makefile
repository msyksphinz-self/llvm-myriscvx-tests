CFLAGS =
CFLAGS += -mcmodel=medany
CFLAGS += -static
CFLAGS += -std=gnu99
CFLAGS += -O2
CFLAGS += -ffast-math
CFLAGS += -fno-common
CFLAGS += -fno-builtin-printf
CFLAGS += -static
CFLAGS += -nostdlib
CFLAGS += -nostartfiles
CFLAGS += -lm
CFLAGS += -lgcc
CFLAGS += -T ./link.ld

CLANG 	= ../../../../llvm-myriscvx100/build/bin/clang
LLC   	= ../../../../llvm-myriscvx100/build/bin/llc
DUMP  	= ../../../../llvm-myriscvx100/build/bin/llvm-dis
MC    	= ../../../../llvm-myriscvx100/build/bin/llvm-mc
OBJDUMP = ../../../../llvm-myriscvx100/build/bin/llvm-objdump

COMMON_OPTIONS =
COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O3
# CLANG64_OPTIONS += --target=riscv64-unknown-elf

.PHONY: dhrystone_llvm

all: dhrystone.riscv dhrystone_llvm

dhrystone.riscv: dhrystone.c dhrystone_main.c syscalls.c crt.S
	riscv64-unknown-elf-gcc $(CFLAGS) -o $@ $^


dhrystone_llvm: dhrystone.myriscvx64.static.medany.S dhrystone_main.myriscvx64.static.medany.S

dhrystone.myriscvx64.static.medany.S: dhrystone.riscv64.bc
	$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $< -o $@ > $@.log 2>&1

dhrystone.riscv64.bc: dhrystone.c
	$(CLANG) $(CLANG64_OPTIONS) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

dhrystone_main.myriscvx64.static.medany.S: dhrystone_main.riscv64.bc
	$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $< -o $@ > $@.log 2>&1

dhrystone_main.riscv64.bc: dhrystone_main.c
	$(CLANG) $(CLANG64_OPTIONS) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll
