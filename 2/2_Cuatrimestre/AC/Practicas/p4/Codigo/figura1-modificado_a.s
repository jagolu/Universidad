	.file	"figura1-modificado_a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"R[0]=%d\tR[39999]=%d\n"
.LC2:
	.string	"Time: %11.9f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	subq	$160056, %rsp
	.cfi_def_cfa_offset 160064
	xorl	%edi, %edi
	leaq	160016(%rsp), %rsi
	call	clock_gettime
	xorl	%r8d, %r8d
	.p2align 4,,10
	.p2align 3
.L2:
	movl	%r8d, %edi
	movl	$s, %eax
	xorl	%esi, %esi
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L3:
	movl	(%rax), %edx
	leal	(%rdi,%rdx,2), %edx
	addl	%edx, %ecx
	movl	4(%rax), %edx
	addq	$8, %rax
	leal	(%rdx,%rdx,2), %edx
	subl	%edi, %edx
	addl	%edx, %esi
	cmpq	$s+40000, %rax
	jne	.L3
	cmpl	%ecx, %esi
	cmovle	%esi, %ecx
	movl	%ecx, 16(%rsp,%r8,4)
	addq	$1, %r8
	cmpq	$40000, %r8
	jne	.L2
	leaq	160032(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	160032(%rsp), %rax
	subq	160016(%rsp), %rax
	movl	$.LC1, %esi
	movl	160012(%rsp), %ecx
	movl	16(%rsp), %edx
	movl	$1, %edi
	cvtsi2sdq	%rax, %xmm0
	movq	160040(%rsp), %rax
	subq	160024(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	xorl	%eax, %eax
	divsd	.LC0(%rip), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rsp)
	call	__printf_chk
	movsd	(%rsp), %xmm0
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	addq	$160056, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.comm	s,40000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
