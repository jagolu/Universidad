	.file	"daxpy.c"
	.comm	x,134217728,32
	.comm	y,134217728,32
	.section	.rodata
	.align 8
.LC0:
	.string	"Falta el tama\303\261o del vector y la constante"
	.align 8
.LC2:
	.string	"Time=%11.9f\ty[0]=%d, y[%d]=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	cmpl	$2, -68(%rbp)
	jg	.L2
	movq	stderr(%rip), %rax
	movq	%rax, %rdx
	movl	$.LC0, %eax
	movq	%rdx, %rcx
	movl	$42, %edx
	movl	$1, %esi
	movq	%rax, %rdi
	call	fwrite
	movl	$-1, %edi
	call	exit
.L2:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -12(%rbp)
	movq	-80(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -4(%rbp)
	cmpl	$33554432, -12(%rbp)
	jle	.L3
	movl	$33554432, -12(%rbp)
.L3:
	movl	$0, -8(%rbp)
	jmp	.L4
.L5:
	movl	-8(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movl	%edx, x(,%rax,4)
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	imull	-8(%rbp), %edx
	movl	-8(%rbp), %eax
	cltq
	movl	%edx, y(,%rax,4)
	addl	$1, -8(%rbp)
.L4:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L5
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movl	$0, -8(%rbp)
	jmp	.L6
.L7:
	movl	-8(%rbp), %eax
	cltq
	movl	x(,%rax,4), %eax
	movl	%eax, %edx
	imull	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	cltq
	movl	y(,%rax,4), %eax
	addl	%eax, %edx
	movl	-8(%rbp), %eax
	cltq
	movl	%edx, y(,%rax,4)
	addl	$1, -8(%rbp)
.L6:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jl	.L7
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$0, %edi
	call	clock_gettime
	movq	-48(%rbp), %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	.LC1(%rip), %xmm2
	divsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	-12(%rbp), %eax
	subl	$1, %eax
	cltq
	movl	y(,%rax,4), %edx
	movl	-12(%rbp), %eax
	leal	-1(%rax), %edi
	movl	y(%rip), %esi
	movl	$.LC2, %eax
	movsd	-24(%rbp), %xmm0
	movl	%edx, %ecx
	movl	%edi, %edx
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
