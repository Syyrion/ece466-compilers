	.file	"test.c"
	.text
.Ltext0:
	.file 0 "/home/rickycui/Documents/cooper_union/compilers" "test.c"
	.globl	u
	.data
	.align 4
	.type	u, @object
	.size	u, 4
u:
	.long	8
	.globl	p
	.align 4
	.type	p, @object
	.size	p, 4
p:
	.long	u
	.globl	s
	.align 4
	.type	s, @object
	.size	s, 4
s:
	.long	4
	.section	.rodata
.LC0:
	.string	"hello world3\n"
	.text
	.globl	f
	.type	f, @function
f:
.LFB0:
	.file 1 "test.c"
	.loc 1 9 1
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	.loc 1 10 5
	subl	$12, %esp
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	.loc 1 11 1
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	f, .-f
	.section	.rodata
.LC1:
	.string	"hello world\n"
.LC2:
	.string	"B %d\n"
.LC3:
	.string	"A %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.loc 1 14 1
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	.loc 1 17 5
	subl	$12, %esp
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	.loc 1 18 5
	movl	-12(%ebp), %eax
	addl	$9, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	.loc 1 19 5
	movl	u, %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	.loc 1 20 1
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0xab
	.value	0x5
	.byte	0x1
	.byte	0x4
	.long	.Ldebug_abbrev0
	.uleb128 0x2
	.long	.LASF2
	.byte	0xc
	.long	.LASF0
	.long	.LASF1
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x1
	.string	"u"
	.byte	0x3
	.byte	0x5
	.long	0x35
	.uleb128 0x5
	.byte	0x3
	.long	u
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x1
	.string	"p"
	.byte	0x5
	.byte	0x6
	.long	0x4b
	.uleb128 0x5
	.byte	0x3
	.long	p
	.uleb128 0x4
	.byte	0x4
	.long	0x35
	.uleb128 0x1
	.string	"s"
	.byte	0x6
	.byte	0x5
	.long	0x35
	.uleb128 0x5
	.byte	0x3
	.long	s
	.uleb128 0x5
	.long	.LASF3
	.byte	0x1
	.byte	0x1
	.byte	0x5
	.long	0x35
	.long	0x72
	.uleb128 0x6
	.byte	0
	.uleb128 0x7
	.long	.LASF4
	.byte	0x1
	.byte	0xd
	.byte	0x5
	.long	0x35
	.long	.LFB1
	.long	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x9a
	.uleb128 0x8
	.string	"a"
	.byte	0x1
	.byte	0xf
	.byte	0x9
	.long	0x35
	.uleb128 0x2
	.byte	0x75
	.sleb128 -12
	.byte	0
	.uleb128 0x9
	.string	"f"
	.byte	0x1
	.byte	0x8
	.byte	0x5
	.long	0x35
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF2:
	.string	"GNU C99 15.1.1 20250425 (Red Hat 15.1.1-1) -m32 -mtune=generic -march=i686 -g -O0 -std=c99"
.LASF4:
	.string	"main"
.LASF3:
	.string	"printf"
	.section	.debug_line_str,"MS",@progbits,1
.LASF0:
	.string	"test.c"
.LASF1:
	.string	"/home/rickycui/Documents/cooper_union/compilers"
	.ident	"GCC: (GNU) 15.1.1 20250425 (Red Hat 15.1.1-1)"
	.section	.note.GNU-stack,"",@progbits
