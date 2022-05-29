TARGET = \
	arith_64bit \
	arith_32bit \
	add_int32 \
	minus_value \
	long_value \
	compare_slt \
	rotate_test \
	cond_if \
	global_variable \
	local_pointer \
	int_array \
	struct_student \
	do_while_count \
	select_exp \
	simple_select_exp \
	switch_table \
	caller_callee


.PHONY: $(TARGET)
all: $(TARGET)

COMMON_OPTIONS =
# COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls

CLANG64_OPTIONS += -DRV64

# CLANG_OPTIONS =
# CLANG_OPTIONS += -O3

add_int32_CLANG_OPTION = -O3
simple_select_exp_CLANG_OPTION = -O3
struct_student_CLANG_OPTION = -O0
select_exp_CLANG_OPTION = -O3

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
