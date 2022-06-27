CLANG = ../../../../llvm-myriscvx100/build/bin/clang
LLC   = ../../../../llvm-myriscvx100/build/bin/llc
DUMP  = ../../../../llvm-myriscvx100/build/bin/llvm-dis


test_global_update.static.riscv: test_global_update.c global_update.myriscvx64.static.medany.S crt.S syscalls.c
	riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	riscv64-unknown-elf-objdump -D $@ > $@.dmp

global_update.myriscvx32.static.medlow.S: global_update.riscv.pic.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o global_update.myriscvx32.static.medlow.S global_update.riscv.static.bc		> global_update.myriscvx32.static.asm.log 2>&1
global_update.myriscvx64.static.medlow.S: global_update.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o global_update.myriscvx64.static.medlow.S global_update.riscv.static.bc		> global_update.myriscvx64.static.asm.log 2>&1

global_update.myriscvx32.static.medany.S: global_update.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o global_update.myriscvx32.static.medany.S global_update.riscv.static.bc		> global_update.myriscvx32.static.asm.log 2>&1
global_update.myriscvx64.static.medany.S: global_update.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o global_update.myriscvx64.static.medany.S global_update.riscv.static.bc		> global_update.myriscvx64.static.asm.log 2>&1

global_update.riscv.static.bc: global_update.c Makefile
	$(CLANG) $(CLANG_OPTIONS) global_update.c -c -target riscv64-unknown-elf -emit-llvm  -o global_update.riscv.static.bc
	$(DUMP) global_update.riscv.static.bc -o global_update.riscv.static.bc.ll


include ../../common.mk
