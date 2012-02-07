.section .data 
	hello: .asciz "Error \n"
.section .bss
.section .text

.global _start

write:
        mov    $1, %rax
        syscall
        ret
        
_start:
        mov (%rsp), %rdi
        mov %rsp, %rsi
        add $8, %rsi
        call   main
 
exit: # just exit not a function
        mov 	%rax, %rdi
        xor    %rax, %rax
        mov    $60, %rax
        syscall
