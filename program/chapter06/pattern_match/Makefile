CLANG = ../../../../llvm-myriscvx100/build/bin/clang
LLC   = ../../../../llvm-myriscvx100/build/bin/llc
DUMP  = ../../../../llvm-myriscvx100/build/bin/llvm-dis

CLANG_OPTIONS += -O3

all: test_pattern_match.riscv

test_pattern_match.riscv: test_pattern_match.c pattern_match.myriscvx64.static.medany.S
	riscv64-unknown-elf-gcc -march=rv64g -O2 $^ -o $@
	riscv64-unknown-elf-objdump -D $@ > $@.dmp

pattern_match.myriscvx32.static.medlow.S: pattern_match.riscv.pic.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o pattern_match.myriscvx32.static.medlow.S pattern_match.riscv.static.bc		> pattern_match.myriscvx32.static.asm.log 2>&1
pattern_match.myriscvx64.static.medlow.S: pattern_match.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o pattern_match.myriscvx64.static.medlow.S pattern_match.riscv.static.bc		> pattern_match.myriscvx64.static.asm.log 2>&1

pattern_match.myriscvx32.static.medany.S: pattern_match.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o pattern_match.myriscvx32.static.medany.S pattern_match.riscv.static.bc		> pattern_match.myriscvx32.static.asm.log 2>&1
pattern_match.myriscvx64.static.medany.S: pattern_match.riscv.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o pattern_match.myriscvx64.static.medany.S pattern_match.riscv.static.bc		> pattern_match.myriscvx64.static.asm.log 2>&1

pattern_match.riscv.static.bc: pattern_match.c Makefile
	$(CLANG) $(CLANG_OPTIONS) pattern_match.c -c -target riscv64-unknown-elf -emit-llvm  -o pattern_match.riscv.static.bc
	$(DUMP) pattern_match.riscv.static.bc -o pattern_match.riscv.static.bc.ll


include ../../common.mk
