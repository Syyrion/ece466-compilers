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
.LC_main_0:
	.string "hello"
	.text
	.globl	main
	.type	main, @function
main:
	pushl   %ebp
	movl    %esp, %ebp
	subl $20, %esp
# temp: 4, local: 1, args: 0
__main_BB0:
# MOV
	movl $0, %eax
	movl %eax, -20(%ebp)
# JP
	jmp __main_BB3

__main_BB1:
# ARGBEGIN
# LEA
	movl $.LC_main_0, -8(%ebp)
# ARG
	pushl -8(%ebp)
# CALL
	call printf
	addl $4, %esp
	movl %eax, -4(%ebp)
__main_BB2:
# MOV
	movl -20(%ebp), %eax
	movl %eax, -12(%ebp)
# ADD
	movl -20(%ebp), %eax
	addl $1, %eax
	movl %eax, -20(%ebp)
__main_BB3:
# CMP
	movl -20(%ebp), %eax
	movl $4, %ecx
	cmp %ecx, %eax
# SETM
	movl $0, %eax
	setl %al
	movl %eax, -16(%ebp)
# CMP
	movl -16(%ebp), %eax
	movl $0, %ecx
	cmp %ecx, %eax
# JPNZ
	jnz __main_BB1

__main_BB4:
# RET
	movl $0, %eax
	leave
	ret
