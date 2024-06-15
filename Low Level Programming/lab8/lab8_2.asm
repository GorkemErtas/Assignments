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
 
 mov ebx, 0
 
 while:
	cmp ebx, 5
	jge end_while
	
	cmp ebx, 3
	jle print
	inc ebx
	jmp while
	
print:
	mov eax, ebx
	call print_int
	inc ebx
	jmp while
	
	
end_while:


 popa
 mov eax, 0 
 leave
 ret