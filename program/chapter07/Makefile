TARGET = func_struct_simple \
	vararg


.PHONY: $(TARGET) func_struct_simple_gcc

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

CLANG32_OPTIONS =
CLANG32_OPTIONS += -O1
# CLANG32_OPTIONS += --target=riscv32-unknown-elf

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O1
# CLANG64_OPTIONS += --target=riscv64-unknown-elf

func_array_byval : func_array_byval.riscv32.gcc \
				   func_array_byval.myriscvx32.static.S \
				   func_array_byval.myriscvx32.pic.S \
				   func_array_byval.riscv32.S

tailcall : tailcall.riscv32.o0.o \
		   tailcall.riscv32.o1.o

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.pic.S \
		$(1).myriscvx64.pic.S

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
