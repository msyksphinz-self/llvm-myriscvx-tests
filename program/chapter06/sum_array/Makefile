CLANG = ../../../../llvm-myriscvx110/build/bin/clang
LLC   = ../../../../llvm-myriscvx110/build/bin/llc
DUMP  = ../../../../llvm-myriscvx110/build/bin/llvm-dis

CLANG_OPTIONS += -O3


test_sum_array.static.riscv: test_sum_array.c sum_array.myriscvx64.static.medany.S
	riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static $^ -o $@
	riscv64-unknown-elf-objdump -D $@ > $@.dmp

#	riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld

sum_array.myriscvx32.static.medlow.S: sum_array.riscv.pic.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o sum_array.myriscvx32.static.medlow.S sum_array.riscv.static.bc		> sum_array.myriscvx32.static.asm.log 2>&1
sum_array.myriscvx64.static.medlow.S: sum_array.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o sum_array.myriscvx64.static.medlow.S sum_array.riscv.static.bc		> sum_array.myriscvx64.static.asm.log 2>&1

sum_array.myriscvx32.static.medany.S: sum_array.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o sum_array.myriscvx32.static.medany.S sum_array.riscv.static.bc		> sum_array.myriscvx32.static.asm.log 2>&1
sum_array.myriscvx64.static.medany.S: sum_array.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o sum_array.myriscvx64.static.medany.S sum_array.riscv.static.bc		> sum_array.myriscvx64.static.asm.log 2>&1

sum_array.riscv.static.bc: sum_array.c Makefile
	$(CLANG) $(CLANG_OPTIONS) sum_array.c -c -target riscv64-unknown-elf -emit-llvm  -o sum_array.riscv.static.bc
	$(DUMP) sum_array.riscv.static.bc -o sum_array.riscv.static.bc.ll


include ../../common.mk
