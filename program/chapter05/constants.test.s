	.text
	.section .mdebug.abilp
	.previous
	.file	"constants.test.ll"
	.globl	main                    # -- Begin function main
	.p2align	2
	.type	main,@function
	.cfi_startproc                  # @main
# %bb.0:
	ret
$func_end0:
	.size	main, ($func_end0)-main
	.cfi_endproc
                                        # -- End function

	.section	".note.GNU-stack","",@progbits
