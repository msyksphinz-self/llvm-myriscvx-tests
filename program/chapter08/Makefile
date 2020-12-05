TARGET = fixup_branch \
	object_test \
	object_sample \
	inline_assembly \
	inline_csr \
	factorial \

.PHONY: all $(TARGET) object_sample assembly_test

ARCH = riscv32 myriscvx32

all : $(TARGET)

test_object_sample: test_object_sample.c object_sample.myriscvx64.static.mod.o
	-PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -march=rv64im -mabi=lp64 test_object_sample.c -c
	-PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-ld -mabi=lp64 test_object_sample.o object_sample.myriscvx64.static.mod.o -o $@

assembly_test: assembly_test.S
	$(MC) -arch=myriscvx32 -debug $< -filetype=asm -o $@.myriscvx32.static.mc.S > $@.myriscvx32.static.mc.S.log 2>&1
	$(MC) -arch=myriscvx64 -debug $< -filetype=asm -o $@.myriscvx64.static.mc.S > $@.myriscvx64.static.mc.S.log 2>&1
	$(MC) -arch=myriscvx32 -debug $< -filetype=obj -o $@.myriscvx32.static.mc.o > $@.myriscvx32.static.mc.o.log 2>&1
	$(MC) -arch=myriscvx64 -debug $< -filetype=obj -o $@.myriscvx64.static.mc.o > $@.myriscvx64.static.mc.o.log 2>&1


pseudo_inst:
	$(MC) -arch=myriscvx32 -debug pseudo_inst.S -filetype=asm -o pseudo_inst.myriscvx32.static.mc.S > pseudo_inst.myriscvx32.static.mc.S.log 2>&1
	$(MC) -arch=myriscvx64 -debug pseudo_inst.S -filetype=asm -o pseudo_inst.myriscvx64.static.mc.S > pseudo_inst.myriscvx64.static.mc.S.log 2>&1
	$(MC) -arch=myriscvx32 -debug pseudo_inst.S -filetype=obj -o pseudo_inst.myriscvx32.static.mc.o > pseudo_inst.myriscvx32.static.mc.o.log 2>&1
	$(MC) -arch=myriscvx64 -debug pseudo_inst.S -filetype=obj -o pseudo_inst.myriscvx64.static.mc.o > pseudo_inst.myriscvx64.static.mc.o.log 2>&1
	$(MC) -arch=riscv32    -debug pseudo_inst.S -filetype=asm -o pseudo_inst.riscv32.static.mc.S 	> pseudo_inst.riscv32.static.mc.S.log 2>&1
	$(MC) -arch=riscv64    -debug pseudo_inst.S -filetype=asm -o pseudo_inst.riscv64.static.mc.S 	> pseudo_inst.riscv64.static.mc.S.log 2>&1
	$(MC) -arch=riscv32    -debug pseudo_inst.S -filetype=obj -o pseudo_inst.riscv32.static.mc.o 	> pseudo_inst.riscv32.static.mc.o.log 2>&1
	$(MC) -arch=riscv64    -debug pseudo_inst.S -filetype=obj -o pseudo_inst.riscv64.static.mc.o 	> pseudo_inst.riscv64.static.mc.o.log 2>&1


objdump_test: objdump_test.S
	$(MC) -arch=myriscvx32 -debug $^ -filetype=obj -o $@.myriscvx32.static.mc.o > $@.myriscvx32.static.mc.o.log 2>&1
	$(MC) -arch=myriscvx64 -debug $^ -filetype=obj -o $@.myriscvx64.static.mc.o > $@.myriscvx64.static.mc.o.log 2>&1
	$(OBJDUMP) -triple=myriscvx32 -d $@.myriscvx32.static.mc.o  > $@.myriscvx32.static.mc.dmp 2>&1
	$(OBJDUMP) -triple=myriscvx64 -d $@.myriscvx64.static.mc.o  > $@.myriscvx64.static.mc.dmp 2>&1

objdump_reloc: objdump_reloc.S
	$(MC) -arch=myriscvx32 -debug $^ -filetype=obj -o $@.myriscvx32.static.mc.o > $@.myriscvx32.static.mc.o.log 2>&1
	$(MC) -arch=myriscvx64 -debug $^ -filetype=obj -o $@.myriscvx64.static.mc.o > $@.myriscvx64.static.mc.o.log 2>&1
	$(OBJDUMP) -triple=myriscvx32 -d $@.myriscvx32.static.mc.o  > $@.myriscvx32.static.mc.dmp 2>&1
	$(OBJDUMP) -triple=myriscvx64 -d $@.myriscvx64.static.mc.o  > $@.myriscvx64.static.mc.dmp 2>&1

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64
RISCV64_LINUX = ${HOME}/riscv64-ctng-linux


COMMON_OPTIONS =
COMMON_OPTIONS += -debug
COMMON_OPTIONS += -disable-tail-calls
# COMMON_OPTIONS += -code-model=medium

CLANG32_OPTIONS =
# CLANG32_OPTIONS += -O1
CLANG32_OPTIONS += --target=riscv32-unknown-elf

CLANG64_OPTIONS =
# CLANG64_OPTIONS += -O1
CLANG64_OPTIONS += --target=riscv64-unknown-elf

include $(realpath ../common.mk ../../common.mk)

define MAKEALL
$(1) :  $(1).myriscvx32.static.S \
		$(1).myriscvx64.static.S \
		$(1).myriscvx32.static.medany.o \
		$(1).myriscvx64.static.medany.o \
		$(1).myriscvx32.static.mc.o \
		$(1).myriscvx64.static.mc.o

$(eval $(call WHOLE_RULES,$(1)))
endef

$(foreach VAR,$(TARGET),$(eval $(call MAKEALL,$(VAR))))
