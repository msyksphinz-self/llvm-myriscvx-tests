TARGET = simple_pattern_match

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O1
CLANG64_OPTIONS += --target=riscv64-unknown-elf

all: test_$(TARGET).riscv

test_$(TARGET).riscv: test_$(TARGET).c $(TARGET).myriscvx64.static.S
	-PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -march=rv64g -mcmodel=medany -O2 $^ -o $@
	-PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
