u:
        .long   8
p:
        .long   u
s:
        .long   4
.LC0:
        .string "hello world3"
f:
        pushl   %ebp
        movl    %esp, %ebp
        subl    $8, %esp
        subl    $12, %esp
        pushl   $.LC0
        call    puts
        addl    $16, %esp
        nop
        leave
        ret
.LC1:
        .string "hello world"
.LC2:
        .string "A %d\n"
.LC3:
        .string "B %d\n"


    .text
	.globl	main
	.type	main, @function
main:
        leal    4(%esp), %ecx
        andl    $-16, %esp
        pushl   -4(%ecx)
        pushl   %ebp
        movl    %esp, %ebp
        pushl   %ecx
        subl    $20, %esp
        subl    $12, %esp
        pushl   $.LC1
        call    puts
        addl    $16, %esp
        movl    -12(%ebp), %eax
        addl    $9, %eax
        subl    $8, %esp
        pushl   %eax
        pushl   $.LC2
        call    printf
        addl    $16, %esp
        movl    u, %eax
        subl    $8, %esp
        pushl   %eax
        pushl   $.LC3
        call    printf
        addl    $16, %esp
        movl    $0, %eax
        movl    -4(%ebp), %ecx
        leave
        leal    -4(%ecx), %esp
        ret
