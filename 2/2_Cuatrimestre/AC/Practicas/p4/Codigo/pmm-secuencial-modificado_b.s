	.file	"pmm-secuencial-modificado_b.c"
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
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
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
	leal	-1(%rbp), %r13d
	xorl	%edx, %edx
	movl	%r13d, %r12d
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
	movl	%r13d, %r11d
	leaq	r+4(,%r12,4), %r15
	xorl	%ecx, %ecx
	shrl	$2, %r11d
	xorl	%r14d, %r14d
	addq	$1, %r11
	salq	$4, %r11
.L9:
	movslq	%r14d, %r12
	leaq	(%r15,%rcx), %r13
	imulq	$20000, %r12, %r12
	leaq	r(%r12), %rbx
	.p2align 4,,10
	.p2align 3
.L12:
	leaq	m1(%r12), %rdx
	xorl	%eax, %eax
	xorl	%r10d, %r10d
	xorl	%r9d, %r9d
	xorl	%r8d, %r8d
	xorl	%edi, %edi
	.p2align 4,,10
	.p2align 3
.L10:
	movl	(%rdx), %esi
	imull	m2T(%rcx,%rax), %esi
	addl	%esi, %edi
	movl	4(%rdx), %esi
	imull	m2T+4(%rcx,%rax), %esi
	addl	%esi, %r8d
	movl	8(%rdx), %esi
	imull	m2T+8(%rcx,%rax), %esi
	addl	%esi, %r9d
	movl	12(%rdx), %esi
	addq	$16, %rdx
	imull	m2T+12(%rcx,%rax), %esi
	addq	$16, %rax
	addl	%esi, %r10d
	cmpq	%r11, %rax
	jne	.L10
	addl	%r8d, %edi
	addl	%edi, %r9d
	addl	%r9d, %r10d
	movl	%r10d, (%rbx)
	addq	$4, %rbx
	cmpq	%r13, %rbx
	jne	.L12
	addl	$1, %r14d
	addq	$20000, %rcx
	cmpl	%ebp, %r14d
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
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
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
