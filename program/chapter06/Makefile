.PHONY: global_variable local_pointer int_array struct_char do_while_count if_ctrl select_exp

all: pointer.o global_variable local_pointer int_array struct_char do_while_count if_ctrl select_exp

CLANG = ../../../llvm-myriscvx80/build/bin/clang
LLC   = ../../../llvm-myriscvx80/build/bin/llc
DUMP  = ../../../llvm-myriscvx80/build/bin/llvm-dis

pointer.o: pointer.c Makefile
	riscv32-unknown-elf-gcc -O3 -o $@ $^ -c
	riscv32-unknown-elf-objdump -D $@ > $@.dmp

global_variable: global_variable.myriscxv32.static.S global_variable.myriscxv32.pic.S
global_variable.myriscxv32.static.S: global_variable.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
global_variable.myriscxv32.pic.S: global_variable.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.riscv32.log
global_variable.bc: global_variable.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll


local_pointer: local_pointer.myriscxv32.static.S local_pointer.myriscxv32.pic.S
local_pointer.myriscxv32.static.S: local_pointer.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
local_pointer.myriscxv32.pic.S: local_pointer.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.myriscvx32.log
local_pointer.riscv32.static.S: local_pointer.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
local_pointer.bc: local_pointer.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll


int_array: int_array.myriscxv32.static.S int_array.myriscxv32.pic.S
int_array.myriscxv32.static.S: int_array.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
int_array.myriscxv32.pic.S: int_array.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.myriscvx32.log
int_array.riscv32.static.S: int_array.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
int_array.bc: int_array.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

struct_char: struct_char.myriscxv32.static.S struct_char.myriscxv32.pic.S
struct_char.myriscxv32.static.S: struct_char.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
struct_char.myriscxv32.pic.S: struct_char.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.myriscvx32.log
struct_char.riscv32.static.S: struct_char.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
struct_char.bc: struct_char.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll


do_while_count: do_while_count.myriscxv32.static.S do_while_count.myriscxv32.pic.S
do_while_count.myriscxv32.static.S: do_while_count.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
do_while_count.myriscxv32.pic.S: do_while_count.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.myriscvx32.log
do_while_count.riscv32.static.S: do_while_count.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
do_while_count.bc: do_while_count.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll

if_ctrl: if_ctrl.myriscxv32.static.S if_ctrl.myriscxv32.pic.S
if_ctrl.myriscxv32.static.S: if_ctrl.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
if_ctrl.myriscxv32.pic.S: if_ctrl.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.myriscvx32.log
if_ctrl.riscv32.static.S: if_ctrl.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
if_ctrl.bc: if_ctrl.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll


select_exp: select_exp.myriscxv32.static.S select_exp.myriscxv32.pic.S
select_exp.myriscxv32.static.S: select_exp.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.myriscvx32.log
select_exp.myriscxv32.pic.S: select_exp.bc Makefile
	$(LLC) -debug -march=myriscvx32 -filetype=asm -relocation-model=pic $< -o $@ 2>&1 | tee $@.myriscvx32.log
select_exp.riscv32.static.S: select_exp.bc Makefile
	$(LLC) -debug -march=riscv32 -filetype=asm -relocation-model=static $< -o $@ 2>&1 | tee $@.riscv32.log
select_exp.bc: select_exp.cpp Makefile
	$(CLANG) $< -c -emit-llvm -o $@
	$(DUMP) $@ -o $@.ll


clean:
	$(RM) -rf *.o *.dmp *.S *.bc
