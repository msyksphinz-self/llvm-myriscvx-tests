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

CLANG ?= ../../../llvm-myriscvx100/build/bin/clang
LLC   ?= ../../../llvm-myriscvx100/build/bin/llc
DUMP  ?= ../../../llvm-myriscvx100/build/bin/llvm-dis

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

func_arguments.o: func_arguments.c Makefile
	riscv32-unknown-elf-gcc -O0 $< -c -o $@
	riscv32-unknown-elf-objdump -d $@ > $@.dmp

zero_return	: zero_return.myriscvx32.gcc zero_return.myriscvx64.gcc  zero_return.riscv32.gcc zero_return.riscv64.gcc
100_return	: 100_return.myriscvx32.gcc  100_return.myriscvx64.gcc   100_return.riscv32.gcc  100_return.riscv64.gcc
constants	: constants.myriscvx32.gcc   constants.myriscvx64.gcc    constants.riscv32.gcc   constants.riscv64.gcc
mem_access  : mem_access.myriscvx32.gcc  mem_access.myriscvx64.gcc   mem_access.riscv32.gcc  mem_access.riscv64.gcc
make_frame  : make_frame.myriscvx32.gcc  make_frame.myriscvx64.gcc   make_frame.riscv32.gcc  make_frame.riscv64.gcc
simple		: simple.myriscvx32.gcc      simple.myriscvx64.gcc       simple.riscv32.gcc      simple.riscv64.gcc
arithmetics	: arithmetics.myriscvx32.gcc arithmetics.myriscvx64.gcc  arithmetics.riscv32.gcc arithmetics.riscv64.gcc
compare_slt	: compare_slt.myriscvx32.gcc compare_slt.myriscvx64.gcc	 compare_slt.riscv32.gcc compare_slt.riscv64.gcc
rotate_test	: rotate_test.myriscvx32.gcc rotate_test.myriscvx64.gcc	 rotate_test.riscv32.gcc rotate_test.riscv64.gcc
# csi_test	: csi_test.myriscvx32.gcc    csi_test.myriscvx64.gcc     csi_test.riscv32.gcc    csi_test.riscv64.gcc

COMMON_OPTIONS =
COMMON_OPTIONS += --debug
COMMON_OPTIONS += -disable-tail-calls
COMMON_OPTIONS += -filetype=asm

CLANG_OPTIONS =
CLANG_OPTIONS += "-O3"

# %.riscv32.gcc: %.cpp Makefile
# 	riscv32-unknown-elf-gcc -O3 -fpic -c $< -o $@
# 	riscv32-unknown-elf-objdump -D $@ > $@.dmp

%.riscv32.gcc: %.riscv32.S Makefile
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -O3 -fpic -c $< -o $@
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -D $@ > $@.dmp
%.riscv64.gcc: %.riscv64.S Makefile
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -O3 -fpic -c $< -o $@
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp
%.myriscvx32.gcc: %.myriscvx32.S Makefile
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -O3 -fpic -c $< -o $@
	PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -D $@ > $@.dmp
%.myriscvx64.gcc: %.myriscvx64.S Makefile
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -O3 -fpic -c $< -o $@
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp

%.riscv32.S: %.bc Makefile
	$(LLC) -march=riscv32  $(COMMON_OPTIONS) $< -o $@ 2>&1 | tee $@.riscv32.log
%.riscv64.S: %.bc Makefile
	$(LLC) -march=riscv64 $(COMMON_OPTIONS) $< -o $@ 2>&1 | tee $@.riscv64.log
%.myriscvx32.S: %.bc Makefile
	$(LLC) -march=myriscvx32 $(COMMON_OPTIONS) $< -o $@ 2>&1 | tee $@.myriscvx32.log
%.myriscvx64.S: %.bc Makefile
	$(LLC) -march=myriscvx64 $(COMMON_OPTIONS) $< -o $@ 2>&1 | tee $@.myriscvx64.log
%.mips32.S: %.mips.bc Makefile
	$(LLC) -march=mips32 $(COMMON_OPTIONS) $< -o $@ 2>&1 | tee $@.mips32.log
%.mips64.S: %.mips.bc Makefile
	$(LLC) -march=mips64 $(COMMON_OPTIONS) $< -o $@ 2>&1 | tee $@.mips64.log
%.bc: %.cpp Makefile
	$(CLANG) $(CLANG_OPTIONS) $< -c -target riscv64-unknown-elf -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll
%.bc: %.c Makefile
	$(CLANG) $(CLANG_OPTIONS) $< -c -target riscv64-unknown-elf -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

%.mips.bc: %.cpp Makefile
	$(CLANG) $(CLANG_OPTIONS) $< -c -target mips64-unknown-elf -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll
%.mips.bc: %.c Makefile
	$(CLANG) $(CLANG_OPTIONS) $< -c -target mips64-unknown-elf -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

clean:
	$(RM) *.gcc *.bc *.S *.bc.ll *.log *.dump
