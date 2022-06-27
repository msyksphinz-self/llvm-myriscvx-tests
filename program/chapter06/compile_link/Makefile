TARGET = global_example.static global_example.pic source1.static.lib source1.pic.lib main.static.lib main.pic.lib

all: $(TARGET)

OBJDUMP_OPTS  =
OBJDUMP_OPTS += -D
OBJDUMP_OPTS += -r
OBJDUMP_OPTS += -t

# GCC     = riscv64-unknown-elf-gcc
# OBJDUMP = riscv64-unknown-elf-objdump
# AR      = riscv64-unknown-elf-ar
# RANLIB  = riscv64-unknown-elf-ranlib

GCC     = riscv64-unknown-linux-gnu-gcc
OBJDUMP = riscv64-unknown-linux-gnu-objdump
AR      = riscv64-unknown-linux-gnu-ar
RANLIB  = riscv64-unknown-linux-gnu-ranlib


global_example.static: main.static.o source1.static.o
	$(GCC) -static $^ -o $@
	$(OBJDUMP) $(OBJDUMP_OPTS) $@ > $@.dmp

global_example.pic: main.pic.o source1.pic.o
	$(GCC) -fpic $^ -o $@
	$(OBJDUMP) $(OBJDUMP_OPTS) $@ > $@.dmp

%.static.o: %.c
	$(GCC) -static $^ -c -o $@
	$(OBJDUMP) $(OBJDUMP_OPTS) $@ > $@.dmp

%.pic.o: %.c
	$(GCC) -fpic $^ -c -o $@
	$(OBJDUMP) $(OBJDUMP_OPTS) $@ > $@.dmp

%.static.lib: %.static.o
	$(AR) r $@ $^
	$(RANLIB) $@
	$(OBJDUMP) $(OBJDUMP_OPTS) $@ > $@.dmp

%.pic.lib: %.pic.o
	$(GCC) -shared -fpic $^ -o $@
	$(OBJDUMP) $(OBJDUMP_OPTS) $@ > $@.dmp

clean:
	rm -f *.o *.dmp *.so *.lib *.static *.pic $(TARGET)
