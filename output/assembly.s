	.data
	.globl printf
	.globl u
u:
	.long 0
	.globl p
p:
	.long 0
	.globl s
s:
	.long 0
	.globl h
	.comm h, 40
	.globl g
g:
	.long 0
	.section	.rodata
.LC_y_0:
	.string "arg %d %d\n"
	.text
	.globl	y
	.type	y, @function
y:
	pushl   %ebp
	movl    %esp, %ebp
	subl $12, %esp
# temp: 3, local: 0, args: 2
__y_BB0:
# ARGBEGIN
# LEA
	movl $.LC_y_0, -8(%ebp)
# ARG
	pushl 12(%ebp)
# ARG
	pushl 8(%ebp)
# ARG
	pushl -8(%ebp)
# CALL
	call printf
	addl $12, %esp
	movl %eax, -4(%ebp)
# DIV
	movl 8(%ebp), %eax
	movl 12(%ebp), %ecx
	cltd
	idivl %ecx
	movl %eax, -12(%ebp)
# RET
	movl -12(%ebp), %eax
	leave
	ret
	.section	.rodata
.LC_main_0:
	.string "%d, %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushl   %ebp
	movl    %esp, %ebp
	subl $64, %esp
# temp: 16, local: 0, args: 0
__main_BB0:
# LEA
	movl $h, -8(%ebp)
# MUL
	movl $3, %edx
	movl $4, %eax
	imull %edx, %eax
	movl %eax, -12(%ebp)
# ADD
	movl -8(%ebp), %eax
	addl -12(%ebp), %eax
	movl %eax, -4(%ebp)
# STORE
	movl $9, %eax
	movl -4(%ebp), %ecx
	movl %eax, (%ecx)
# ARGBEGIN
# LEA
	movl $.LC_main_0, -20(%ebp)
# LEA
	movl $h, -32(%ebp)
# MUL
	movl $3, %edx
	movl $4, %eax
	imull %edx, %eax
	movl %eax, -36(%ebp)
# ADD
	movl -32(%ebp), %eax
	addl -36(%ebp), %eax
	movl %eax, -28(%ebp)
# LOAD
	movl -28(%ebp), %eax
	movl (%eax), %ecx
	movl %ecx, -40(%ebp)
# LEA
	movl $h, -48(%ebp)
# LEA
	movl $h, -56(%ebp)
# MUL
	movl $3, %edx
	movl $4, %eax
	imull %edx, %eax
	movl %eax, -60(%ebp)
# ADD
	movl -56(%ebp), %eax
	addl -60(%ebp), %eax
	movl %eax, -52(%ebp)
# SUB
	movl -48(%ebp), %eax
	subl -52(%ebp), %eax
	movl %eax, -64(%ebp)
# DIV
	movl -64(%ebp), %eax
	movl $4, %ecx
	cltd
	idivl %ecx
	movl %eax, -44(%ebp)
# ARG
	pushl -44(%ebp)
# ARG
	pushl -40(%ebp)
# ARG
	pushl -20(%ebp)
# CALL
	call printf
	addl $12, %esp
	movl %eax, -16(%ebp)
# RET
	movl $0, %eax
	leave
	ret
