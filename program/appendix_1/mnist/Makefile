#Project settings
PROJECT = libfixmath
LIB =
SRC = .
INC =

# Compile rules.
.PHONY : all
all: train_twolayernet_fix16

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

CLANG64_OPTIONS =
CLANG64_OPTIONS += -O1
CLANG64_OPTIONS += --target=riscv64-unknown-elf

CLANG 	?= $(realpath ../../../../../llvm-myriscvx100/build/bin/clang        ../../../../llvm-myriscvx100/build/bin/clang     )
LLC   	?= $(realpath ../../../../../llvm-myriscvx100/build/bin/llc		     ../../../../llvm-myriscvx100/build/bin/llc		  )
DUMP  	?= $(realpath ../../../../../llvm-myriscvx100/build/bin/llvm-dis	 ../../../../llvm-myriscvx100/build/bin/llvm-dis  )
MC    	?= $(realpath ../../../../../llvm-myriscvx100/build/bin/llvm-mc	     ../../../../llvm-myriscvx100/build/bin/llvm-mc	  )
OBJDUMP ?= $(realpath ../../../../../llvm-myriscvx100/build/bin/llvm-objdump ../../../../llvm-myriscvx100/build/bin/llvm-objdump)

DEFINES += FIXMATH_NO_CACHE

CPP_FLAGS = -O2 $(INC) -Wall -Wextra -c -std=gnu11 -O3 -g  -g -march=rv32imac -mabi=ilp32 -mcmodel=medany $(addprefix -D, $(DEFINES))
CC_FLAGS  = -O2 $(INC) -Wall -Wextra -c -std=gnu11 -O3 -g  -g -march=rv32imac -mabi=ilp32 -mcmodel=medany $(addprefix -D, $(DEFINES))
AS_FLAGS  = $(CC_FLAGS) -D_ASSEMBLER_
LD_FLAGS = -Wall

OBJ_FILES = train_twolayernet_fix16.o

# Find all source files
$(PROJECT).a: $(OBJ_FILES)
	$(AR) rcs $(PROJECT).a $(OBJ)

.c.o:
	$(CLANG) $(CLANG64_OPTIONS) $< -c -emit-llvm -o $@.bc
	$(LLC) -march=myriscvx64 $(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $@.S $@.bc
	riscv64-unknown-elf-gcc -c $@.S -o $@

train_twolayernet_fix16: train_twolayernet_fix16.o libfixmath/fix16.o crt.S syscalls.c t10k-images-idx3-ubyte.o t10k-labels-idx1-ubyte.o wb0_init.o wb1_init.o wh0_init.o wh1_init.o
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-gcc -march=rv64g -DPREALLOCATE=1 -static -mcmodel=medany -std=gnu99 -O2 -ffast-math -fno-common -fno-builtin-printf -nostdlib -nostartfiles -lm -lgcc $^ -o $@ -T link.ld
	PATH=$(RISCV64)/bin LD_LIBRARY_PATH=$(RISCV64)/lib riscv64-unknown-elf-objdump -D $@ > $@.dmp

t10k-images-idx3-ubyte.o: t10k-images-idx3-ubyte
	riscv64-unknown-elf-objcopy -I binary -O elf64-littleriscv -B riscv --rename-section .data=.rodata $< $@

t10k-labels-idx1-ubyte.o: t10k-labels-idx1-ubyte
	riscv64-unknown-elf-objcopy -I binary -O elf64-littleriscv -B riscv --rename-section .data=.rodata $< $@

train_data: train-images-idx3-ubyte train-labels-idx1-ubyte
t10k_data: t10k-images-idx3-ubyte t10k-labels-idx1-ubyte

%-ubyte: %-ubyte.gz
	gunzip $^

%_init.o: %.bin
	riscv64-unknown-elf-objcopy -I binary -O elf64-littleriscv -B riscv --rename-section .data=.rodata $< $@

%.gz:
	wget "http://yann.lecun.com/exdb/mnist/$@"

# Clean rules
clean:
	rm -f $(PROJECT).a $(OBJ_FILES) *.o
