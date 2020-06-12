TARGET = fp_mem \
	fp_ops_simple \
	fp_ops \
	fp_args \
	fp_cmp \
	fp_others \
	fp_constant
ARCH = riscv32 myriscvx32

.PHONY: all $(TARGET)

CLANG 	= ../../../llvm-myriscvx100/build/bin/clang
LLC   	= ../../../llvm-myriscvx100/build/bin/llc
DUMP  	= ../../../llvm-myriscvx100/build/bin/llvm-dis
MC    	= ../../../llvm-myriscvx100/build/bin/llvm-mc
OBJDUMP = ../../../llvm-myriscvx100/build/bin/llvm-objdump

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64
RISCV64_LINUX = ${HOME}/riscv64-ctng-linux


COMMON_OPTIONS =
COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls
# COMMON_OPTIONS += -code-model=medium

CLANG32_OPTIONS =
# CLANG32_OPTIONS += -O3
# CLANG32_OPTIONS += --target=riscv32-unknown-elf

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O3
CLANG64_OPTIONS += --target=riscv64-unknown-elf
# CLANG64_OPTIONS += -O1
# CLANG64_OPTIONS += --target=riscv64-unknown-elf
include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.static.o \
		$(1).myriscvx64.static.o
$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
