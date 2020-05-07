TARGET = \
	cond_if \
	global_variable \
	local_pointer \
	int_array \
	struct_char \
	do_while_count \
	if_ctrl \
	select_exp

.PHONY: $(TARGET)
all: $(TARGET)

pointer.o: pointer.c Makefile
	riscv32-unknown-elf-gcc -O3 -o $@ $^ -c
	riscv32-unknown-elf-objdump -D $@ > $@.dmp

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) : $(1).myriscvx32.gcc $(1).myriscvx64.gcc
$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
