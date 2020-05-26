TARGET = fixup_branch object_test object_sample
ARCH = riscv32 myriscvx32

.PHONY: all $(TARGET) object_sample

test_object_sample: test_object_sample.c object_sample.myriscvx64.static.medany.mod.o crt.S syscalls.c
	riscv64-unknown-elf-gcc -march=rv64im -mabi=lp64 -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld


object_sample.myriscvx64.static.medany.mod.o:
	$(MAKE) -C ../ object_sample.myriscvx64.static.medany.o
	cp ../object_sample.myriscvx64.static.medany.o object_sample.myriscvx64.static.medany.mod.o
	perl -p -i.back -e 's/\xf8/\xf3/g' object_sample.myriscvx64.static.medany.mod.o
