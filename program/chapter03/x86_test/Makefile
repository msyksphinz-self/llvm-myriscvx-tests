all: x86_test_direct x86_test

include $(realpath ../common.mk ../../common.mk)

x86_test_direct: x86_test.c
	$(CLANG) $^

x86_test: x86_test.c
	$(CLANG) $@ -emit-llvm -c
	$(LLVM_DIS) $@.bc
	$(LLC) $@.bc -filetype=asm
	gcc x86_test.s -o $@
