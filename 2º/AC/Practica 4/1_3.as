.LC1:
        .string "Tiempo: %ld\nPrimer componente: %f\nUltimo componente: %f\n"
main:
        pushq   %rbx
        subq    $320000, %rsp
        call    std::chrono::_V2::system_clock::now()
        xorl    %edx, %edx
        pxor    %xmm4, %xmm4
        movq    %rax, %rbx
.L4:
        pxor    %xmm3, %xmm3
        pxor    %xmm2, %xmm2
        movapd  %xmm4, %xmm1
        movl    %edx, %eax
        cvtsi2sdl       %edx, %xmm3
        negl    %eax
        movapd  %xmm4, %xmm0
        cvtsi2sdl       %eax, %xmm2
        movl    $5000, %eax
.L2:
        addsd   %xmm3, %xmm0
        addsd   %xmm2, %xmm1
        subl    $1, %eax
        jne     .L2
        minsd   %xmm1, %xmm0
        movsd   %xmm0, (%rsp,%rdx,8)
        addq    $1, %rdx
        cmpq    $40000, %rdx
        jne     .L4
        call    std::chrono::_V2::system_clock::now()
        movsd   (%rsp), %xmm0
        movl    $.LC1, %edi
        movsd   319992(%rsp), %xmm1
        subq    %rbx, %rax
        movq    %rax, %rsi
        movl    $2, %eax
        call    printf
        addq    $320000, %rsp
        xorl    %eax, %eax
        popq    %rbx
        ret