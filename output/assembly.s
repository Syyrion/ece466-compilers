	.data
	.globl g
g:
	.long 4

.LC0:
	.string "result: %X %d\n"

	.text
	.globl	main
	.type	main, @function
main:
	pushl   %ebp
	movl    %esp, %ebp
	subl $240, %esp

#	movl $-3, %ebx
#	movl $-2, %ecx

#	movl $0, %eax
#	subl $10, %eax
# ebx <=> ecx
#	cmp %ecx, %ebx

#	movl $0, %eax
#	setl %al

	movl $-3, %eax
	movl $100, %ebx
	mul %ebx

	pushl %eax
	pushl %eax
	pushl $.LC0
	call printf

	leave
	ret
