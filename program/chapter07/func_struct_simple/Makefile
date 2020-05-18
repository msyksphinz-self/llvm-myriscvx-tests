TARGET = func_struct_simple

.PHONY: $(TARGET) func_struct_simple_gcc

all: $(TARGET) test_func_struct_simple test_func_struct_simple_rv32 func_struct_simple_gcc

CLANG_OPTIONS =
CLANG_OPTIONS += -O1
# CLANG_OPTIONS += -m32
CLANG_OPTIONS += --target=riscv32-unknown-elf
# CLANG_OPTIONS += --target=riscv64-unknown-elf

test_func_struct_simple: test_$(TARGET).c $(TARGET).myriscvx64.static.medany.S crt.S syscalls.c
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp

test_func_struct_simple_rv32: test_$(TARGET).c $(TARGET).myriscvx32.static.medany.S
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -march=rv32gc -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -lm -lgcc $^ -o $@
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -D $@ > $@.dmp

test_func_struct_simple_gcc_rv32: test_$(TARGET).c $(TARGET).c
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 $^ -o $@
#	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -g -march=rv32ima -mabi=ilp32 -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -c syscalls.c
#	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -g -march=rv32ima -mabi=ilp32 -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ syscalls.o -o $@ -T link.ld
#	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -D $@ > $@.dmp

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
