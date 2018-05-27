	.file	"figura1-modificado_b.c"
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
	movl	%r8d, %edx
	movl	$s, %eax
	xorl	%edi, %edi
	xorl	%ecx, %ecx
	xorl	%r9d, %r9d
	.p2align 4,,10
	.p2align 3
.L3:
	movl	4(%rax), %esi
	movl	(%rax), %r10d
	addl	$10, %edi
	movl	32(%rax), %r11d
	leal	(%rsi,%rsi,2), %esi
	leal	(%rdx,%r10,2), %r10d
	leal	(%rdx,%r11,2), %r11d
	subl	%edx, %esi
	addl	%r10d, %r9d
	movl	8(%rax), %r10d
	addl	%esi, %ecx
	movl	12(%rax), %esi
	leal	(%rdx,%r10,2), %r10d
	leal	(%rsi,%rsi,2), %esi
	addl	%r10d, %r9d
	movl	16(%rax), %r10d
	subl	%edx, %esi
	addl	%esi, %ecx
	movl	20(%rax), %esi
	leal	(%rdx,%r10,2), %r10d
	leal	(%rsi,%rsi,2), %esi
	addl	%r9d, %r10d
	movl	24(%rax), %r9d
	subl	%edx, %esi
	addl	%esi, %ecx
	movl	28(%rax), %esi
	leal	(%rdx,%r9,2), %r9d
	addl	%r10d, %r9d
	movl	40(%rax), %r10d
	leal	(%rsi,%rsi,2), %esi
	addl	%r9d, %r11d
	movl	48(%rax), %r9d
	subl	%edx, %esi
	leal	(%rdx,%r10,2), %r10d
	addl	%ecx, %esi
	movl	36(%rax), %ecx
	leal	(%rdx,%r9,2), %r9d
	addl	%r11d, %r10d
	movl	56(%rax), %r11d
	addl	%r10d, %r9d
	movl	64(%rax), %r10d
	leal	(%rcx,%rcx,2), %ecx
	leal	(%rdx,%r11,2), %r11d
	subl	%edx, %ecx
	leal	(%rdx,%r10,2), %r10d
	addl	%ecx, %esi
	movl	44(%rax), %ecx
	addl	%r9d, %r11d
	movl	72(%rax), %r9d
	addl	%r11d, %r10d
	leal	(%rcx,%rcx,2), %ecx
	leal	(%rdx,%r9,2), %r9d
	subl	%edx, %ecx
	addl	%ecx, %esi
	movl	52(%rax), %ecx
	addl	%r10d, %r9d
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %esi
	movl	60(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %esi
	movl	68(%rax), %ecx
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%ecx, %esi
	movl	76(%rax), %ecx
	addq	$80, %rax
	leal	(%rcx,%rcx,2), %ecx
	subl	%edx, %ecx
	addl	%esi, %ecx
	cmpl	$5000, %edi
	jne	.L3
	cmpl	%r9d, %ecx
	cmovg	%r9d, %ecx
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
