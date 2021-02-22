.section .data

#ifndef TEST
#define TEST 3
#endif
.macro linea

#if TEST==1
.int -1,-1,-1,-1
#elif TEST==2
.int 0x04000000,0x04000000,0x04000000,0x04000000
#elif TEST==3
.int 0x08000000,0x08000000,0x08000000,0x08000000
#elif TEST==4
.int 0x10000000,0x10000000,0x10000000,0x10000000
#elif TEST==5
.int 0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff
#elif TEST==6
.int 0x80000000,0x80000000,0x80000000,0x80000000
#elif TEST==7
.int 0xf0000000,0xf0000000,0xf0000000,0xf0000000
#elif TEST==8
.int 0xf8000000,0xf8000000,0xf8000000,0xf8000000
#elif TEST==9
.int 0xf7ffffff,0xf7ffffff,0xf7ffffff,0xf7ffffff
#elif TEST==10
.int 100000000,100000000,100000000,100000000
#elif TEST==11
.int 200000000,200000000,200000000,200000000
#elif TEST==12
.int 300000000,300000000,300000000,300000000
#elif TEST==13
.int 2000000000,2000000000,2000000000,2000000000
#elif TEST==14
.int 3000000000,3000000000,3000000000,3000000000
#elif TEST==15
.int -100000000,-100000000,-100000000,-100000000
#elif TEST==16
.int -200000000,-200000000,-200000000,-200000000
#elif TEST==17
.int -300000000,-300000000,-300000000,-300000000
#elif TEST==18
.int -2000000000,-2000000000,-2000000000,-2000000000
#elif TEST==19
.int -3000000000,-3000000000,-3000000000,-3000000000
#else
.error "Definit TEST entre 1..19"
#endif
.endm

lista:	.irpc i,1234
	linea
	.endr

longlista: 	.int   (.-lista)/4
resultado:	.int   0,0
  formato: 	.asciz	"suma = %ld = 0x%lx hex\n"

.section .text
#_start: .global _start
main: .global  main

	call trabajar	# subrutina de usuario
	call imprim_C	# printf()  de libC
	call acabar_C	# exit()    de libC

trabajar:
	mov     $lista, %rbx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	
	mov  %edx, resultado+4
	mov  %eax, resultado
	ret

suma:
	push     %rsi
	mov  $0, %eax
	mov  $0, %edx
	mov  $0, %rsi
	mov  $0, %ebp

	bucle:
		mov  (%rbx,%rsi,4), %ebp
		test %ebp, %ebp
		jns positivo
		add %ebp, %eax
		adc $0xffffffff, %edx
		jmp continua
		positivo:
		add %ebp, %eax
		adc   $0, %edx #
		continua:
		inc   %rsi
		cmp   %rsi,%rcx
		jne    bucle
		pop   %rsi

	ret


imprim_C:			# requiere libC
	mov   $formato, %rdi
	mov   resultado,%rsi
	mov   resultado,%rdx
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);
	ret

acabar_L:
	mov        $60, %rax
	mov  resultado, %edi
	syscall			# == _exit(resultado)
	ret

acabar_C:			# requiere libC
	mov  resultado, %edi
	call _exit		# ==  exit(resultado)
	ret
