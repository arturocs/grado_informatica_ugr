.section .data

#ifndef TEST
#define TEST 5
#endif
.macro linea

#if TEST==1
.int 1,1,1,1
#elif TEST==2
.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
#elif TEST==3
.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
#elif TEST==4
.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
#elif TEST==5
.int -1,-1,-1,-1
#elif TEST==6
.int 200000000,200000000,200000000,200000000
#elif TEST==7
.int 300000000,300000000,300000000,300000000
#elif TEST==8
.int 5000000000,5000000000,5000000000,5000000000
#else
.error "Definir TEST entre 1..8"
#endif
.endm

lista:	.irpc i,1234
	linea
	.endr

longlista: 	.int   (.-lista)/4
resultado:	.int   0,0
  formato: 	.asciz	"suma = %lu = 0x%lx hex\n"

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

	bucle:
		add  (%rbx,%rsi,4), %eax
		jnc  etiqueta
		inc   %edx
		etiqueta:
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

acabar_C:			# requiere libC
	mov  resultado, %edi
	call _exit		# ==  exit(resultado)
	ret
