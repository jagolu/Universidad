	.file	"pmm-secuencial-modificado_a.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Falta tama\303\261o\n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Tiempo= %11.9f\n\t(0,0)=%d\n\t(%d, %d)=%d\n"
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
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$32, %rsp
	.cfi_def_cfa_offset 64
	subl	$1, %edi
	jle	.L22
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	movl	$5000, %ebp
	call	strtol
	cmpl	$5000, %eax
	cmovle	%eax, %ebp
	testl	%ebp, %ebp
	jle	.L23
	leal	-1(%rbp), %r12d
	xorl	%edx, %edx
	leaq	1(%r12), %rbx
	imulq	$20000, %rbx, %rcx
	salq	$2, %rbx
.L6:
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	movl	$0, r(%rdx,%rax)
	movl	$2, m1(%rdx,%rax)
	movl	$4, m2(%rdx,%rax)
	addq	$4, %rax
	cmpq	%rbx, %rax
	jne	.L5
	addq	$20000, %rdx
	cmpq	%rcx, %rdx
	jne	.L6
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
	xorl	%esi, %esi
	xorl	%edi, %edi
.L7:
	movslq	%edi, %rax
	leaq	m2(,%rax,4), %rdx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	movl	(%rdx), %ecx
	addq	$20000, %rdx
	movl	%ecx, m2T(%rsi,%rax)
	addq	$4, %rax
	cmpq	%rbx, %rax
	jne	.L8
	addl	$1, %edi
	addq	$20000, %rsi
	cmpl	%ebp, %edi
	jne	.L7
	leaq	r+4(,%r12,4), %r10
	xorl	%esi, %esi
	xorl	%r9d, %r9d
.L9:
	movslq	%r9d, %rdi
	leaq	(%r10,%rsi), %r8
	imulq	$20000, %rdi, %rdi
	addq	$r, %rdi
	.p2align 4,,10
	.p2align 3
.L12:
	movl	(%rdi), %ecx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L10:
	movl	m1(%rsi,%rax), %edx
	imull	m2T(%rsi,%rax), %edx
	addq	$4, %rax
	addl	%edx, %ecx
	cmpq	%rbx, %rax
	jne	.L10
	movl	%ecx, (%rdi)
	addq	$4, %rdi
	cmpq	%r8, %rdi
	jne	.L12
	addl	$1, %r9d
	addq	$20000, %rsi
	cmpl	%ebp, %r9d
	jne	.L9
	jmp	.L13
.L23:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
.L13:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	leal	-1(%rbp), %ecx
	movl	$.LC2, %esi
	movl	$1, %edi
	movslq	%ecx, %rdx
	movl	%ecx, %r8d
	imulq	$20004, %rdx, %rdx
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	movl	r(%rdx), %r9d
	movl	r(%rip), %edx
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
.L22:
	.cfi_restore_state
	movq	stderr(%rip), %rcx
	movl	$.LC0, %edi
	movl	$14, %edx
	movl	$1, %esi
	call	fwrite
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE34:
	.size	main, .-main
	.comm	m2T,100000000,32
	.comm	r,100000000,32
	.comm	m2,100000000,32
	.comm	m1,100000000,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
