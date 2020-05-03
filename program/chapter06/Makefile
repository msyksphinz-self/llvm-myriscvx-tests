.PHONY: cond_if global_variable local_pointer int_array struct_char do_while_count if_ctrl select_exp

all: pointer.o global_variable local_pointer int_array struct_char do_while_count if_ctrl select_exp

CLANG = ../../../llvm-myriscvx80/build/bin/clang
LLC   = ../../../llvm-myriscvx80/build/bin/llc
DUMP  = ../../../llvm-myriscvx80/build/bin/llvm-dis

pointer.o: pointer.c Makefile
	riscv32-unknown-elf-gcc -O3 -o $@ $^ -c
	riscv32-unknown-elf-objdump -D $@ > $@.dmp

cond_if			: cond_if.myriscxv32.static.S cond_if.myriscxv32.pic.S
global_variable	: $@.myriscxv32.static.S $@.myriscxv32.pic.S
local_pointer	: local_pointer.myriscxv32.static.S local_pointer.myriscxv32.pic.S
int_array		: int_array.myriscxv32.static.S int_array.myriscxv32.pic.S
struct_char		: struct_char.myriscxv32.static.S struct_char.myriscxv32.pic.S
do_while_count	: do_while_count.myriscxv32.static.S do_while_count.myriscxv32.pic.S
select_exp		: select_exp.myriscxv32.static.S select_exp.myriscxv32.pic.S

%.myriscxv32.static.S: %.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
%.myriscxv32.pic.S: %.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.riscv32.log
%.bc: %.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll







clean:
	$(RM) -rf *.o *.dmp *.S *.bc
