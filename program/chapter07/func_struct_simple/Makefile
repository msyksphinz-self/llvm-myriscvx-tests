TARGET ?= func_struct_simple

.PHONY: $(TARGET)

all: $(TARGET) test_$(TARGET)_rv64 test_$(TARGET)_rv32 test_$(TARGET)_gcc_rv32 test_$(TARGET)_gcc_rv64

# CLANG32_OPTIONS =
# CLANG32_OPTIONS += -O1
# CLANG32_OPTIONS += --target=riscv32-unknown-elf
#
# CLANG64_OPTIONS =
# CLANG64_OPTIONS += -O1
# CLANG64_OPTIONS += --target=riscv64-unknown-elf

test_$(TARGET)_rv64: test_$(TARGET).c $(TARGET).myriscvx64.static.medany.S crt.S syscalls.c $(TARGET).h
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp

test_$(TARGET)_rv32: test_$(TARGET).c $(TARGET).myriscvx32.static.medany.S $(TARGET).h
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -march=rv32g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -lm -lgcc $^ -o $@
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -D $@ > $@.dmp

test_$(TARGET)_gcc_rv64: test_$(TARGET).c $(TARGET).c $(TARGET).h
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -O2 $^ -o $@

test_$(TARGET)_gcc_rv32: test_$(TARGET).c $(TARGET).c $(TARGET).h
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -O2 $^ -o $@

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
