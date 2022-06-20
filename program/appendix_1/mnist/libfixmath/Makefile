#Project settings
PROJECT = libfixmath
LIB =
SRC = .
INC =

# Compile rules.
.PHONY : all
all: $(PROJECT).a

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

OBJ_FILES = fix16.o

# Find all source files
$(PROJECT).a: $(OBJ_FILES)
	$(AR) rcs $(PROJECT).a $(OBJ)

.c.o:
	$(CLANG) $(CLANG64_OPTIONS) $< -c -emit-llvm -o $@.bc
	$(LLC) -march=myriscvx64 $(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm -o $@.S $@.bc
	riscv64-unknown-elf-gcc -c $@.S -o $@

# Clean rules
clean:
	rm -f $(PROJECT).a $(OBJ_FILES)
