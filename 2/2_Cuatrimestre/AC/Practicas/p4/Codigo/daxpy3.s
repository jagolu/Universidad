	.file	"daxpy.c"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"Falta el tama\303\261o del vector y la constante"
	.align 8
.LC4:
	.string	"Time=%11.9f\ty[0]=%d, y[%d]=%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB34:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rsi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subq	$48, %rsp
	.cfi_def_cfa_offset 96
	cmpl	$2, %edi
	jle	.L23
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	movq	16(%rbp), %rdi
	movl	%eax, %ebx
	xorl	%esi, %esi
	movl	$10, %edx
	movl	$33554432, %ebp
	call	strtol
	cmpl	$33554432, %ebx
	movl	%eax, %r12d
	cmovle	%ebx, %ebp
	testl	%ebp, %ebp
	jle	.L3
	movl	%ebp, %ebx
	shrl	$2, %ebx
	cmpl	$3, %ebp
	leal	0(,%rbx,4), %r13d
	setbe	%r14b
	testl	%r13d, %r13d
	sete	%al
	orb	%al, %r14b
	jne	.L14
	movdqa	.LC2(%rip), %xmm4
	xorl	%eax, %eax
	xorl	%edx, %edx
	movdqa	.LC0(%rip), %xmm0
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L15:
	movdqa	%xmm3, %xmm0
.L5:
	movdqa	%xmm0, %xmm2
	addl	$1, %edx
	movdqa	%xmm0, %xmm1
	movdqa	%xmm0, %xmm3
	pmuludq	%xmm0, %xmm2
	movdqa	%xmm0, x(%rax)
	psrldq	$4, %xmm1
	pmuludq	%xmm1, %xmm1
	pshufd	$8, %xmm2, %xmm0
	paddd	%xmm4, %xmm3
	pshufd	$8, %xmm1, %xmm1
	punpckldq	%xmm1, %xmm0
	movdqa	%xmm0, y(%rax)
	addq	$16, %rax
	cmpl	%ebx, %edx
	jb	.L15
	cmpl	%r13d, %ebp
	movl	%r13d, %eax
	je	.L24
	.p2align 4,,10
	.p2align 3
.L18:
	movl	%eax, %ecx
	movslq	%eax, %rdx
	imull	%eax, %ecx
	movl	%eax, x(,%rdx,4)
	addl	$1, %eax
	cmpl	%eax, %ebp
	movl	%ecx, y(,%rdx,4)
	jg	.L18
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	testb	%r14b, %r14b
	jne	.L16
.L13:
	movl	%r12d, 12(%rsp)
	xorl	%eax, %eax
	xorl	%edx, %edx
	movd	12(%rsp), %xmm0
	pshufd	$0, %xmm0, %xmm2
	.p2align 4,,10
	.p2align 3
.L9:
	movdqa	x(%rax), %xmm1
	addl	$1, %edx
	movdqa	%xmm2, %xmm0
	movdqa	%xmm2, %xmm3
	pmuludq	%xmm1, %xmm0
	psrldq	$4, %xmm1
	pshufd	$8, %xmm0, %xmm0
	psrldq	$4, %xmm3
	pmuludq	%xmm3, %xmm1
	pshufd	$8, %xmm1, %xmm1
	punpckldq	%xmm1, %xmm0
	paddd	y(%rax), %xmm0
	movdqa	%xmm0, y(%rax)
	addq	$16, %rax
	cmpl	%ebx, %edx
	jb	.L9
	cmpl	%r13d, %ebp
	je	.L12
	.p2align 4,,10
	.p2align 3
.L17:
	movslq	%r13d, %rax
	addl	$1, %r13d
	movl	x(,%rax,4), %edx
	imull	%r12d, %edx
	addl	%edx, y(,%rax,4)
	cmpl	%r13d, %ebp
	jg	.L17
.L12:
	leaq	32(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	leal	-1(%rbp), %ecx
	movl	$.LC4, %esi
	movl	$1, %edi
	movslq	%ecx, %rdx
	movl	y(,%rdx,4), %r8d
	movl	y(%rip), %edx
	cvtsi2sdq	%rax, %xmm0
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %eax
	divsd	.LC3(%rip), %xmm1
	addsd	%xmm1, %xmm0
	call	__printf_chk
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore_state
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L12
.L23:
	movq	stderr(%rip), %rcx
	movl	$.LC1, %edi
	movl	$42, %edx
	movl	$1, %esi
	call	fwrite
	orl	$-1, %edi
	call	exit
.L16:
	xorl	%r13d, %r13d
	jmp	.L17
.L24:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	jmp	.L13
.L14:
	xorl	%eax, %eax
	jmp	.L18
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.comm	y,134217728,32
	.comm	x,134217728,32
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC2:
	.long	4
	.long	4
	.long	4
	.long	4
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC3:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
