%include "asm_io.inc"


 segment .data
 msg db "Enter an integer: ", 0
 outmsg db "Binary representation: ", 0

 segment .bss


 input1 resb 5
 input2 resb 3

 segment .text
 global _asm_main
 _asm_main:
 enter 0,0 
 pusha

 while:
	mov eax, msg
	call print_string
	call read_int
	mov ebx, eax
	cmp eax, 0
	je end_while
	mov eax, outmsg
	call print_string
	
	mov ecx, 32
	loop_start:
		mov edx, 0
		sal ebx,1
		adc edx, 0
		mov eax, edx
		call print_int
		loop loop_start
		
	call print_nl
	jmp while	
		
 end_while:
	

 popa
 mov eax, 0 
 leave
 ret