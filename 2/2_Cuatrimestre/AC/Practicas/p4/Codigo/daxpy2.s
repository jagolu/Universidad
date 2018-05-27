	.file	"daxpy.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Falta el tama\303\261o del vector y la constante"
	.align 8
.LC2:
	.string	"Time=%11.9f\ty[0]=%d, y[%d]=%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB34:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	cmpl	$2, %edi
	jle	.L10
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	movl	$33554432, %r12d
	call	strtol
	movq	16(%rbp), %rdi
	movl	%eax, %ebx
	xorl	%esi, %esi
	movl	$10, %edx
	call	strtol
	cmpl	$33554432, %ebx
	movl	%eax, %ebp
	cmovle	%ebx, %r12d
	testl	%r12d, %r12d
	jle	.L3
	leal	-1(%r12), %edx
	xorl	%ebx, %ebx
	addq	$1, %rdx
	.p2align 4,,10
	.p2align 3
.L4:
	movl	%ebx, %eax
	movl	%ebx, x(,%rbx,4)
	imull	%ebx, %eax
	movl	%eax, y(,%rbx,4)
	addq	$1, %rbx
	cmpq	%rdx, %rbx
	jne	.L4
	movq	%rsp, %rsi
	xorl	%edi, %edi
	salq	$2, %rbx
	call	clock_gettime
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	movl	x(%rax), %edx
	imull	%ebp, %edx
	addl	%edx, y(%rax)
	addq	$4, %rax
	cmpq	%rbx, %rax
	jne	.L5
.L6:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	leal	-1(%r12), %ecx
	movl	$.LC2, %esi
	movl	$1, %edi
	movslq	%ecx, %rdx
	movl	y(,%rdx,4), %r8d
	movl	y(%rip), %edx
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC1(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore_state
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L6
.L10:
	movq	stderr(%rip), %rcx
	movl	$.LC0, %edi
	movl	$42, %edx
	movl	$1, %esi
	call	fwrite
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.comm	y,134217728,32
	.comm	x,134217728,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
