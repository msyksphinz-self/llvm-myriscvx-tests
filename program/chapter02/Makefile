.PHONY: all

all: llvm_ir_sample.ll Makefile

%.ll : %.bc Makefile
	llvm-dis-7 $< -o $@
%.bc : %.c Makefile
	clang-7 -O1 $< -c -emit-llvm -o $@

clean:
	$(RM) *.bc *.ll
