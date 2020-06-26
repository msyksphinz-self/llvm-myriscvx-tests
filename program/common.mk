CLANG 	?= $(realpath ../../../llvm-myriscvx100-1st/build/bin/clang        ../../../../llvm-myriscvx100-1st/build/bin/clang       )
LLC   	?= $(realpath ../../../llvm-myriscvx100-1st/build/bin/llc		   ../../../../llvm-myriscvx100-1st/build/bin/llc		  )
DUMP  	?= $(realpath ../../../llvm-myriscvx100-1st/build/bin/llvm-dis	   ../../../../llvm-myriscvx100-1st/build/bin/llvm-dis	  )
MC    	?= $(realpath ../../../llvm-myriscvx100-1st/build/bin/llvm-mc	   ../../../../llvm-myriscvx100-1st/build/bin/llvm-mc	  )
OBJDUMP ?= $(realpath ../../../llvm-myriscvx100-1st/build/bin/llvm-objdump ../../../../llvm-myriscvx100-1st/build/bin/llvm-objdump)

RISCV32 = ${HOME}/riscv32
RISCV64 = ${HOME}/riscv64

func_arguments.o: func_arguments.c Makefile
	riscv32-unknown-elf-gcc -O0 $< -c -o $@
	riscv32-unknown-elf-objdump -d $@ > $@.dmp

COMMON_OPTIONS += $(LLC_OPTIONS)

VIEW_DAG := 0
VIEW_FUNC := 0

ifneq ($(VIEW_DAG),0)
	COMMON_OPTIONS += --view-dag-combine1-dags
	COMMON_OPTIONS += --view-legalize-dags
	COMMON_OPTIONS += --view-dag-combine2-dags
	COMMON_OPTIONS += --view-isel-dags
	COMMON_OPTIONS += --view-sched-dags
ifneq ($(VIEW_FUNC),0)
	COMMON_OPTIONS += --filter-view-dags=$(VIEW_FUNC)
endif
endif


define WHOLE_RULES

# $(1): $(1).myriscvx32.static.S.o $(1).myriscvx32.pic.S.o $(1).riscv32.static.S.o $(1).riscv32.pic.S.o \
# 	$(1).myriscvx32.static.o $(1).myriscvx32.pic.o $(1).riscv32.static.o $(1).riscv32.pic.o \
# 	$(1).myriscvx32.static.S $(1).myriscvx32.pic.S $(1).riscv32.static.S $(1).riscv32.pic.S

$(1).riscv32.static.S.o   : $(1).riscv32.static.S Makefile
	-$(MC)      --arch=riscv32 $(1).riscv32.static.S --filetype=obj --debug -o $(1).riscv32.static.o > $(1).riscv32.static.S.o.log 2>&1
	-$(OBJDUMP) -r -D $(1).riscv32.static.o > $(1).riscv32.static.dmp
$(1).riscv32.pic.S.o      : $(1).riscv32.pic.S Makefile
	-$(MC)      --arch=riscv32 $(1).riscv32.pic.S --filetype=obj --debug -o $(1).riscv32.pic.o > $(1).riscv32.pic.S.o.log 2>&1
	-$(OBJDUMP) -r -D $(1).riscv32.pic.o > $(1).riscv32.pic.dmp
$(1).myriscvx32.static.S.o: $(1).myriscvx32.static.S Makefile
	-$(MC)      --arch=myriscvx32 $(1).myriscvx32.static.S --filetype=obj --debug -o $(1).myriscvx32.static.o > $(1).myriscvx32.static.S.o.log 2>&1
	-$(OBJDUMP) -r -D $(1).myriscvx32.static.o > $(1).myriscvx32.static.dmp
$(1).myriscvx32.pic.S.o   : $(1).myriscvx32.pic.S Makefile
	-$(MC)      --arch=myriscvx32 $(1).myriscvx32.pic.S --filetype=obj --debug -o $(1).myriscvx32.pic.o > $(1).myriscvx32.pic.S.o.log 2>&1
	-$(OBJDUMP) -r -D $(1).myriscvx32.pic.o > $(1).myriscvx32.pic.dmp
$(1).mips32.static.S.o: $(1).mips32.static.S Makefile
	-PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -O3 -c $(1).mips32.static.S -o $(1).mips32.static.S.o
	-PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -r -D $(1).mips32.static.S.o > $(1).mips32.static.dmp
$(1).mips32.pic.S.o   : $(1).mips32.pic.S Makefile
	-PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-gcc -O3 -c $(1).mips32.pic.S -o $(1).mips32.pic.S.o
	-PATH=$(RISCV32)/bin LD_LIBRARY_PATH=$(RISCV32)/lib riscv32-unknown-elf-objdump -r -D $(1).mips32.pic.S.o > $(1).mips32.pic.dmp


$(1).riscv32.static.S: $(1).riscv32.static.bc Makefile
	-$(LLC) -march=riscv32		$(COMMON_OPTIONS) -relocation-model=static -filetype=asm  $(1).riscv32.static.bc -o $(1).riscv32.static.S		> $(1).riscv32.static.asm.log 2>&1
$(1).riscv64.static.S: $(1).riscv64.static.bc Makefile
	-$(LLC) -march=riscv64		$(COMMON_OPTIONS) -relocation-model=static -filetype=asm  $(1).riscv64.static.bc -o $(1).riscv64.static.S		> $(1).riscv64.static.asm.log 2>&1
$(1).riscv32.static.o: $(1).riscv32.static.bc Makefile
	-$(LLC) -march=riscv32		$(COMMON_OPTIONS) -relocation-model=static -filetype=obj  $(1).riscv32.static.bc -o $(1).riscv32.static.o		> $(1).riscv32.static.obj.log 2>&1
$(1).riscv64.static.o: $(1).riscv64.static.bc Makefile
	-$(LLC) -march=riscv64		$(COMMON_OPTIONS) -relocation-model=static -filetype=obj  $(1).riscv64.static.bc -o $(1).riscv64.static.o		> $(1).riscv64.static.obj.log 2>&1
$(1).myriscvx32.static.S: $(1).riscv32.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static -filetype=asm $(1).riscv32.static.bc -o $(1).myriscvx32.static.S	> $(1).myriscvx32.static.asm.log 2>&1
$(1).myriscvx64.static.S: $(1).riscv64.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static -filetype=asm $(1).riscv64.static.bc -o $(1).myriscvx64.static.S	> $(1).myriscvx64.static.asm.log 2>&1
$(1).myriscvx32.static.o: $(1).riscv32.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static -filetype=obj $(1).riscv32.static.bc -o $(1).myriscvx32.static.o	> $(1).myriscvx32.static.obj.log 2>&1
$(1).myriscvx64.static.o: $(1).riscv64.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static -filetype=obj $(1).riscv64.static.bc -o $(1).myriscvx64.static.o	> $(1).myriscvx64.static.obj.log 2>&1
$(1).mips32.static.S: $(1).mips.bc Makefile
	-$(LLC) -march=mips			$(COMMON_OPTIONS) -relocation-model=static -filetype=asm $(1).riscv32.static.bc -o $(1).mips32.static.S		> $(1).mips32.static.asm.log 2>&1
$(1).mips64.static.S: $(1).mips.bc Makefile
	-$(LLC) -march=mips64		$(COMMON_OPTIONS) -relocation-model=static -filetype=asm $(1).riscv64.static.bc -o $(1).mips64.static.S		> $(1).mips64.static.asm.log 2>&1
$(1).mips32.static.o: $(1).mips.bc Makefile
	-$(LLC) -march=mips			$(COMMON_OPTIONS) -relocation-model=static -filetype=obj $(1).riscv32.static.bc -o $(1).mips32.static.o		> $(1).mips32.static.obj.log 2>&1
$(1).mips64.static.o: $(1).mips.bc Makefile
	-$(LLC) -march=mips64		$(COMMON_OPTIONS) -relocation-model=static -filetype=obj $(1).riscv64.static.bc -o $(1).mips64.static.o		> $(1).mips64.static.obj.log 2>&1
$(1).myriscvx32.static.medany.S: $(1).riscv32.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $(1).riscv32.static.bc -o $(1).myriscvx32.static.medany.S		> $(1).myriscvx32.static.asm.log 2>&1
$(1).myriscvx64.static.medany.S: $(1).riscv64.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=asm $(1).riscv64.static.bc -o $(1).myriscvx64.static.medany.S		> $(1).myriscvx64.static.asm.log 2>&1
$(1).myriscvx32.static.medany.o: $(1).riscv32.static.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=obj $(1).riscv32.static.bc -o $(1).myriscvx32.static.medany.o		> $(1).myriscvx32.static.obj.log 2>&1
$(1).myriscvx64.static.medany.o: $(1).riscv64.static.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=static --code-model=medium -filetype=obj $(1).riscv64.static.bc -o $(1).myriscvx64.static.medany.o		> $(1).myriscvx64.static.obj.log 2>&1

$(1).riscv32.pic.S: $(1).riscv32.pic.bc Makefile
	-$(LLC) -march=riscv32		$(COMMON_OPTIONS) -relocation-model=pic -filetype=asm $(1).riscv32.pic.bc -o $(1).riscv32.pic.S   		> $(1).riscv32.pic.asm.log 2>&1
$(1).riscv64.pic.S: $(1).riscv64.pic.bc Makefile
	-$(LLC) -march=riscv64		$(COMMON_OPTIONS) -relocation-model=pic -filetype=asm $(1).riscv64.pic.bc -o $(1).riscv64.pic.S   	    > $(1).riscv64.pic.asm.log 2>&1
$(1).riscv32.pic.o: $(1).riscv32.pic.bc Makefile
	-$(LLC) -march=riscv32		$(COMMON_OPTIONS) -relocation-model=pic -filetype=obj $(1).riscv32.pic.bc -o $(1).riscv32.pic.o   		> $(1).riscv32.pic.obj.log 2>&1
$(1).riscv64.pic.o: $(1).riscv64.pic.bc Makefile
	-$(LLC) -march=riscv64		$(COMMON_OPTIONS) -relocation-model=pic -filetype=obj $(1).riscv64.pic.bc -o $(1).riscv64.pic.o   		> $(1).riscv64.pic.obj.log 2>&1
$(1).myriscvx32.pic.S: $(1).riscv32.pic.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=pic -filetype=asm $(1).riscv32.pic.bc -o $(1).myriscvx32.pic.S		> $(1).myriscvx32.pic.asm.log 2>&1
$(1).myriscvx64.pic.S: $(1).riscv64.pic.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=pic -filetype=asm $(1).riscv64.pic.bc -o $(1).myriscvx64.pic.S		> $(1).myriscvx64.pic.asm.log 2>&1

$(1).myriscvx32.pic.o: $(1).riscv32.pic.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=pic -filetype=obj $(1).riscv32.pic.bc -o $(1).myriscvx32.pic.o		> $(1).myriscvx32.pic.obj.log 2>&1
$(1).myriscvx64.pic.o: $(1).riscv64.pic.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=pic -filetype=obj $(1).riscv64.pic.bc -o $(1).myriscvx64.pic.o		> $(1).myriscvx64.pic.obj.log 2>&1
$(1).myriscvx32.pic.medany.S: $(1).riscv32.pic.bc Makefile
	-$(LLC) -march=myriscvx32	$(COMMON_OPTIONS) -relocation-model=pic --code-model=medium -filetype=asm $(1).riscv32.pic.bc -o $(1).myriscvx32.pic.medany.S		> $(1).myriscvx32.pic.asm.log 2>&1
$(1).myriscvx64.pic.medany.S: $(1).riscv64.pic.bc Makefile
	-$(LLC) -march=myriscvx64	$(COMMON_OPTIONS) -relocation-model=pic --code-model=medium -filetype=asm $(1).riscv64.pic.bc -o $(1).myriscvx64.pic.medany.S		> $(1).myriscvx64.pic.asm.log 2>&1
$(1).mips32.pic.S: $(1).mips.bc Makefile
	-$(LLC) -march=mips			$(COMMON_OPTIONS) -relocation-model=pic -filetype=asm $(1).mips.bc -o $(1).mips32.pic.S				> $(1).mips32.pic.asm.log 2>&1
$(1).mips64.pic.S: $(1).mips.bc Makefile
	-$(LLC) -march=mips64		$(COMMON_OPTIONS) -relocation-model=pic -filetype=asm $(1).mips.bc -o $(1).mips64.pic.S				> $(1).mips64.pic.asm.log 2>&1
$(1).mips32.pic.o: $(1).mips.bc Makefile
	-$(LLC) -march=mips			$(COMMON_OPTIONS) -relocation-model=pic -filetype=obj $(1).mips.bc -o $(1).mips32.pic.o				> $(1).mips32.pic.obj.log 2>&1
$(1).mips64.pic.o: $(1).mips.bc Makefile
	-$(LLC) -march=mips64		$(COMMON_OPTIONS) -relocation-model=pic -filetype=obj $(1).mips.bc -o $(1).mips64.pic.o				> $(1).mips64.pic.obj.log 2>&1

$(1).riscv32.pic.bc: $(1).c Makefile
	$(CLANG) $(CLANG32_OPTIONS) -fpic -c $(1).c -emit-llvm -o $(1).riscv32.pic.bc
	$(DUMP) $(1).riscv32.pic.bc -o $(1).riscv32.pic.bc.ll

$(1).riscv32.static.bc: $(1).c Makefile
	$(CLANG) $(CLANG32_OPTIONS) $(1).c -c -emit-llvm -o $(1).riscv32.static.bc
	$(DUMP) $(1).riscv32.static.bc -o $(1).riscv32.static.bc.ll

$(1).riscv64.pic.bc: $(1).c Makefile
	$(CLANG) $(CLANG64_OPTIONS) -fpic -c $(1).c -emit-llvm -o $(1).riscv64.pic.bc
	$(DUMP) $(1).riscv64.pic.bc -o $(1).riscv64.pic.bc.ll

$(1).riscv64.static.bc: $(1).c Makefile
	$(CLANG) $(CLANG64_OPTIONS) $(1).c -c -emit-llvm -o $(1).riscv64.static.bc
	$(DUMP) $(1).riscv64.static.bc -o $(1).riscv64.static.bc.ll

$(1).myriscvx64.static.mc.o: $(1).myriscvx64.static.S Makefile
	$(MC) --arch=myriscvx64 --debug $(1).myriscvx64.static.S -o $(1).myriscvx64.static.mc.o \
		> $(1).myriscvx64.static.mc.o.log 2>&1

$(1).myriscvx32.static.mc.o: $(1).myriscvx32.static.S Makefile
	$(MC) --arch=myriscvx32 --debug $(1).myriscvx32.static.S -o $(1).myriscvx32.static.mc.o \
		> $(1).myriscvx32.static.mc.o.log 2>&1

endef  # WHOLE_RULES

dotbook:
	../../../dot_book_wrapper.sh $(TARGET)

clean:
	$(RM) *.gcc *.bc *.riscv*.S *.myriscvx*.S *.bc.ll *.log *.dump *.dmp *.o *.riscv *.gcc $(CLEAN)
