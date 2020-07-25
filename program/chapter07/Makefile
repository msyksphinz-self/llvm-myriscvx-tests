TARGET = func_struct_call \
	vararg \
	tailcall \
	factorial


.PHONY: $(TARGET) func_struct_simple_gcc \
	tailcall.myriscvx32.tailcall.S \
	tailcall.myriscvx32.notailcall.S \
	tailcall.myriscvx64.tailcall.S \
	tailcall.myriscvx64.notailcall.S

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

vararg_CLANG_OPTION = -O3

CLANG32_OPTIONS =
# CLANG32_OPTIONS += -O1
CLANG32_OPTIONS += --target=riscv32-unknown-elf

CLANG64_OPTIONS =
# CLANG64_OPTIONS += -O1
CLANG64_OPTIONS += --target=riscv64-unknown-elf

func_array_byval : func_array_byval.riscv32.gcc \
				   func_array_byval.myriscvx32.static.S \
				   func_array_byval.myriscvx32.pic.S \
				   func_array_byval.riscv32.S

tailcall : tailcall.myriscvx32.tailcall.S \
	       tailcall.myriscvx32.notailcall.S \
		   tailcall.myriscvx64.tailcall.S \
		   tailcall.myriscvx64.notailcall.S


tailcall.myriscvx32.tailcall.S:
	$(MAKE) tailcall.myriscvx32.static.S CLANG32_OPTIONS="-O1" LLC_OPTIONS="-tailcallopt"
	mv tailcall.myriscvx32.static.S $@

tailcall.myriscvx32.notailcall.S:
	$(MAKE) tailcall.myriscvx32.static.S CLANG32_OPTIONS="-O0"
	mv tailcall.myriscvx32.static.S $@

tailcall.myriscvx64.tailcall.S:
	$(MAKE) tailcall.myriscvx64.static.S CLANG32_OPTIONS="-O1" LLC_OPTIONS="-tailcallopt"
	mv tailcall.myriscvx64.static.S $@

tailcall.myriscvx64.notailcall.S:
	$(MAKE) tailcall.myriscvx64.static.S CLANG32_OPTIONS="-O0"
	mv tailcall.myriscvx64.static.S $@


include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
