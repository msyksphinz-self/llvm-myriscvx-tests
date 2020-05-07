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

include ../common.mk
