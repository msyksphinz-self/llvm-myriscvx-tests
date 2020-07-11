TARGET = \
	zero_return \
	constants \
	mem_access \
	make_frame \
	simple \
	arithmetics \
	compare_slt \
	rotate_test \
	csi_test \
	100_return \
	simple_pattern_match

.PHONY: $(TARGET)
all: $(TARGET)

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

COMMON_OPTIONS =
COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls

CLANG32_OPTIONS =
# CLANG32_OPTIONS += -O1
CLANG32_OPTIONS += --target=riscv32-unknown-elf

CLANG64_OPTIONS =
# CLANG64_OPTIONS += -O1
CLANG64_OPTIONS += --target=riscv64-unknown-elf

arithmetics_CLANG_OPTION = -O3

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
