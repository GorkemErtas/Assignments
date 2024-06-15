%include "asm_io.inc"

 segment .data
 L1 db "Enter an integer: ", 0
 L2 db "Min: ", 0
 
 
 segment .bss

 segment .text
 global _asm_main
 _asm_main:
 enter 0,0 
 pusha
 
 mov ebx, 07FFFFFFFh
	

 while:
	mov eax, L1
	call print_string
	call read_int

	cmp eax, 0
	je end_while

	cmp eax, ebx
	jl assign
	jmp while
	assign:
		mov ebx, eax
		jmp while
 
 end_while:
	mov eax, L2
	call print_string
	mov eax, ebx
	call print_int
 
 
 popa
 mov eax, 0 
 leave
 ret