	.file	"daxpy.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta el tama\303\261o del vector y la constante"
.LC2:
	.string	"Time=%11.9f\ty[0]=%d, y[%d]=%d\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB17:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rsi, %rbx
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	cmpl	$2, %edi
	jg	.L2
	movq	stderr(%rip), %rsi
	movl	$.LC0, %edi
	call	fputs
	orl	$-1, %edi
	call	exit
.L2:
	movq	8(%rsi), %rdi
	call	atoi
	movq	16(%rbx), %rdi
	movl	%eax, %r12d
	movl	$33554432, %ebx
	call	atoi
	cmpl	$33554432, %r12d
	movl	%eax, %ebp
	cmovle	%r12d, %ebx
	xorl	%eax, %eax
	jmp	.L3
.L4:
	imull	%edx, %edx
	movl	%eax, x(,%rax,4)
	movl	%edx, y(,%rax,4)
	incq	%rax
.L3:
	cmpl	%ebx, %eax
	movl	%eax, %edx
	jl	.L4
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%eax, %eax
	jmp	.L5
.L6:
	movl	x(,%rax,4), %edx
	imull	%ebp, %edx
	addl	%edx, y(,%rax,4)
	incq	%rax
.L5:
	cmpl	%eax, %ebx
	jg	.L6
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	leal	-1(%rbx), %ecx
	movl	$.LC2, %esi
	movl	$1, %edi
	movslq	%ecx, %rdx
	movl	y(,%rdx,4), %r8d
	movl	y(%rip), %edx
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movb	$1, %al
	divsd	.LC1(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	addq	$32, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE17:
	.size	main, .-main
	.comm	y,134217728,16
	.comm	x,134217728,16
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
