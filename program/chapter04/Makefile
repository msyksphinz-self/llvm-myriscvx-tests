TARGET = \
	simple_func


.PHONY: $(TARGET)
all: $(TARGET)

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

COMMON_OPTIONS =
COMMON_OPTIONS += -disable-tail-calls

CLANG32_OPTIONS =
# CLANG32_OPTIONS += -O3
CLANG32_OPTIONS += --target=riscv32-unknown-elf

CLANG64_OPTIONS =
# CLANG64_OPTIONS += -O3
CLANG64_OPTIONS += --target=riscv64-unknown-elf
CLANG64_OPTIONS += -DRV64

# arithmetics_CLANG_OPTION = -O3
compare_slt_CLANG_OPTION = -O3
rotate_test_CLANG_OPTION = -O3

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
