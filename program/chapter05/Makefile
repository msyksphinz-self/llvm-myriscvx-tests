TARGET = \
	simple_func \
	value_return \
	func_arg \
	cond \
	frame_offset \
	zero_return \
	constants \
	mem_access \
	make_frame \
	add_int32 \
	arithmetics \
	arith_64bit \
	arith_32bit \
	compare_slt \
	rotate_test \
	csi_test \
	100_return \
	shift_insts \
	simple_pattern_match \
	long_value \
	minus_value


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
