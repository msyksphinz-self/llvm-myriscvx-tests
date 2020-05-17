TARGET = func_struct_simple

.PHONY: $(TARGET) func_struct_simple_gcc

all: $(TARGET) test_func_struct_simple test_func_struct_simple_rv32 func_struct_simple_gcc

CLANG_OPTIONS =
CLANG_OPTIONS += -O1

test_func_struct_simple: test_$(TARGET).c $(TARGET).myriscvx64.static.medany.S crt.S syscalls.c
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp

test_func_struct_simple_rv32: test_$(TARGET).c $(TARGET).myriscvx32.static.medany.S
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -march=rv32gc -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -lm -lgcc $^ -o $@
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -D $@ > $@.dmp

func_struct_simple_gcc: func_struct_simple.c Makefile #
	PATH=${RISCV32}/bin/ LD_LIBRARY_PATH=${RISCV32}/lib riscv32-unknown-elf-gcc -O3 -c $< -S -o - > func_struct_simple.rv32.S
	PATH=${RISCV64}/bin/ LD_LIBRARY_PATH=${RISCV64}/lib riscv64-unknown-elf-gcc -O3 -c $< -S -o - > func_struct_simple.rv64.S

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
