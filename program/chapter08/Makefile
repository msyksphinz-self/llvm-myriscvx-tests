TARGET = fixup_branch object_test object_sample
ARCH = riscv32 myriscvx32

.PHONY: all $(TARGET) object_sample

CLANG 	= ../../../llvm-myriscvx100/build/bin/clang
LLC   	= ../../../llvm-myriscvx100/build/bin/llc
DUMP  	= ../../../llvm-myriscvx100/build/bin/llvm-dis
MC    	= ../../../llvm-myriscvx100/build/bin/llvm-mc
OBJDUMP = ../../../llvm-myriscvx80/build/bin/llvm-objdump

# CLANG = ../../../llvm-myriscvx80/build/bin/clang
# LLC   = ../../../llvm-myriscvx100/build/bin/llc
# DUMP  = ../../../llvm-myriscvx100/build/bin/llvm-dis
# MC    = ../../../llvm-myriscvx100/build/bin/llvm-mc
# OBJDUMP = ../../../llvm-myriscvx100/build/bin/llvm-objdump

test_object_sample: test_object_sample.c object_sample.myriscvx64.static.mod.o
	riscv64-unknown-elf-gcc -march=rv64im -mabi=lp64 test_object_sample.c -c
	riscv64-unknown-elf-ld -mabi=lp64 test_object_sample.o object_sample.myriscvx64.static.mod.o -o $@


RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64
RISCV64_LINUX = ${HOME}/riscv64-ctng-linux


COMMON_OPTIONS =
COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls
# COMMON_OPTIONS += -code-model=medium

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.static.medany.o \
		$(1).myriscvx64.static.medany.o

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
