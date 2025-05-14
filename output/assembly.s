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
	subl $8, %esp
# temp: 2, local: 0, args: 2
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
	movl %eax, -4(%ebp)
# RET
	movl $0, %eax
	leave
	ret
	.section	.rodata
.LC_main_0:
	.string "hello world %d, %d\n"
.LC_main_1:
	.string "ret %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushl   %ebp
	movl    %esp, %ebp
	subl $36, %esp
# temp: 8, local: 1, args: 0
__main_BB0:
# MOV
	movl $0, %eax
	movl %eax, -36(%ebp)
# JP
	jmp __main_BB3

__main_BB1:
# ARGBEGIN
# LEA
	movl $.LC_main_0, -8(%ebp)
# MUL
	movl -36(%ebp), %edx
	movl $2, %eax
	imull %edx, %eax
	movl %eax, -12(%ebp)
# ARG
	pushl -12(%ebp)
# ARG
	pushl -36(%ebp)
# ARG
	pushl -8(%ebp)
# CALL
	call printf
	movl %eax, -4(%ebp)
__main_BB2:
# MOV
	movl -36(%ebp), %eax
	movl %eax, -16(%ebp)
# ADD
	movl -36(%ebp), %eax
	addl $1, %eax
	movl %eax, -36(%ebp)
__main_BB3:
# CMP
	movl -36(%ebp), %eax
	movl $3, %ecx
	cmp %ecx, %eax
# SETM
	movl $0, %eax
	setl %al
	movl %eax, -20(%ebp)
# CMP
	movl -20(%ebp), %eax
	movl $0, %ecx
	cmp %ecx, %eax
# JPNZ
	jnz __main_BB1

__main_BB4:
# ARGBEGIN
# LEA
	movl $.LC_main_1, -28(%ebp)
# ARGBEGIN
# ARG
	pushl $4
# ARG
	pushl $10
# CALL
	call y
	movl %eax, -32(%ebp)
# ARG
	pushl -32(%ebp)
# ARG
	pushl -28(%ebp)
# CALL
	call printf
	movl %eax, -24(%ebp)
# RET
	leave
	ret
