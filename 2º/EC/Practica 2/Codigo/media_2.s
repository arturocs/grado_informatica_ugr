.section .data

#ifndef TEST
#define TEST 3
#endif
.macro linea

#if TEST==1
.int 1,2,1,2
#elif TEST==2
.int -1,-2,-1,-2
#elif TEST==3
.int 0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff
#elif TEST==4
.int 0x80000000,0x80000000,0x80000000,0x80000000
#elif TEST==5
.int 0x7fffffff,0x7fffffff,0x7fffffff,0x7fffffff
#elif TEST==6
.int 200000000,200000000,200000000,200000000
#elif TEST==7
.int 300000000,300000000,300000000,300000000
#elif TEST==8
.int -200000000,-200000000,-200000000,-200000000
#elif TEST==9
.int -300000000,-300000000,-300000000,-300000000
#elif TEST==10
.int 0,2,1,1
#elif TEST==11
.int 1,2,1,1
#elif TEST==12
.int 8,2,1,1
#elif TEST==13
.int 15,2,1,1
#elif TEST==14
.int 16,2,1,1
#elif TEST==15
.int 0,-2,-1,-1
#elif TEST==16
.int -1,-2,-1,-1
#elif TEST==17
.int -8,-2,-1,-1
#elif TEST==18
.int -15,-2,-1,-1
#elif TEST==19
.int -16,-2,-1,-1
#else
.error "Definit TEST entre 1..19"
#endif
.endm

formatq: 	.ascii "64-bit: resultado=%i \t resto=%i  \n"
lista:	.irpc i,1234
	linea
	.endr
longlista: 	.int   (.-lista)/4
resultado:	.int 0,0
resto:		.int 0,0
formato: 	.ascii "resultado=%i \t resto=%i  \n"

.section .text

main: .global  main

	call trabajar	# subrutina de usuario
	mov $formato, %r8
	call imprim_C	# printf()  de libC
	mov  $lista, %rbx
    mov  longlista, %ecx
    call sumaq
    mov  %rax, resultado
    mov  %rdx, resto
	mov $formatq, %r8
	call imprim_C
	call acabar_C	# exit()    de libC
	

trabajar:
	mov     $lista, %rbx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov  %edx, resto
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
		adc   $0, %edx 
		continua:
		inc   %rsi
		cmp   %rsi,%rcx
		jne    bucle
		idiv  %esi 
		pop   %rsi

	ret


imprim_C:			# requiere libC
	mov   %r8, %rdi
	mov   resto,%rdx
	mov   resultado,%rsi
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);
	ret

acabar_C:			# requiere libC
	mov  resultado, %edi
	call _exit		# ==  exit(resultado)
	ret

    
sumaq:
	push     %rsi
    mov   $0,%rax
    mov   $0,%rsi

	bucleq:
	movslq  (%rbx,%rsi,4),%rdi
	add     %rdi,%rax
	inc     %rsi
	cmp     %rsi,%rcx
	jne     bucleq
	test    %rax,%rax
	jns     positivoq
	mov     $-1,%rdx
	jmp     continuaq
	positivoq:
	mov     $0,%rdx
	continuaq:
	idiv    %rsi
	pop   %rsi
ret
