all: pointer.o

pointer.o: pointer.c Makefile
	riscv32-unknown-elf-gcc -O3 -o $@ $^ -c
	riscv32-unknown-elf-objdump -D $@ > $@.dmp

clean:
	$(RM) -rf *.o *.dmp
