	.file	"pmm-secuencial.c"
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
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$40, %rsp
	.cfi_def_cfa_offset 80
	subl	$1, %edi
	jle	.L18
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	movl	$5000, %r12d
	call	strtol
	cmpl	$5000, %eax
	cmovle	%eax, %r12d
	testl	%r12d, %r12d
	jle	.L19
	leal	-1(%r12), %ebp
	xorl	%edx, %edx
	addq	$1, %rbp
	imulq	$20000, %rbp, %r13
	leaq	0(,%rbp,4), %rbx
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
	cmpq	%r13, %rdx
	jne	.L6
	xorl	%edi, %edi
	movq	%rsp, %rsi
	call	clock_gettime
	xorl	%edi, %edi
.L7:
	xorl	%r8d, %r8d
	.p2align 4,,10
	.p2align 3
.L10:
	movl	r(%rdi,%r8,4), %esi
	movslq	%r8d, %rax
	leaq	m2(,%rax,4), %rcx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L8:
	movl	m1(%rdi,%rax), %edx
	addq	$4, %rax
	imull	(%rcx), %edx
	addq	$20000, %rcx
	addl	%edx, %esi
	cmpq	%rbx, %rax
	jne	.L8
	movl	%esi, r(%rdi,%r8,4)
	addq	$1, %r8
	cmpq	%rbp, %r8
	jne	.L10
	addq	$20000, %rdi
	cmpq	%r13, %rdi
	jne	.L7
	jmp	.L11
.L19:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime
.L11:
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	leal	-1(%r12), %ecx
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
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L18:
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
