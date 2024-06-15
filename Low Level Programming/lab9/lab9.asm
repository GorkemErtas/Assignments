%include "asm_io.inc"


 segment .data
 
 msg1 db "Enter an integer: ", 0
 msg2 db "Binary representation: ", 0
 msg3 db "Semantic: ", 0
 msg4 db "YNGR/IPHN/HULU/SWRS count: ", 0
 msg5 db "*/ANDR/*/STRK count: ", 0
 codes db "YNGR", 0, "OLDR", 0, "ANDR", 0, "IPHN", 0, "NFLX", 0, "DISN", 0, "SWRS", 0, "STRK", 0
 four_spaces db " ",0


 segment .bss

 input resd 1 ; only 4 bytes! 

 segment .text
 global _asm_main
 _asm_main:
 enter 0,0 
 pusha
 
 mov eax, msg1
 call print_string
 call read_int
 mov ebx, eax
 mov edx, eax
 
 mov eax, msg2
 call print_string

 mov ecx, 32
 loop_start:
	mov eax, 0
	sal ebx,1
	adc eax, 0
	call print_int
 loop loop_start
		
 call print_nl
 
 mov eax, msg3
 call print_string
 
 mov ecx, 8
 mov eax, 0
 
 loop2_start:
 
 mov eax, 0
 sal edx, 1 
 adc eax, 0
 cmp eax, 0
 je younger
 jmp older
 label1:
 
 mov eax, 0
 sal edx, 1
 adc eax, 0
 cmp eax, 0
 je ANDR
 jmp IPHN
 label2:
 
 mov eax, 0
 sal edx, 1
 adc eax, 0
 cmp eax, 0
 je NFLX
 jmp DISN
 label3:
 
 mov eax, 0
 sal edx, 1
 adc eax, 0
 cmp eax, 0
 je SWRS
 jmp STRK
 label4:
 
 call print_nl
 dec ecx
 cmp ecx,0
 je end
 jmp loop2_start
 
 
 younger:
 mov eax, codes
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label1
 
 older:
 mov eax, codes+5
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label1
 
 ANDR:
 mov eax, codes+10
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label2
 
 IPHN:
 mov eax, codes+15
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label2
 
 NFLX:
 mov eax, codes+20
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label3
 
 DISN:
 mov eax, codes+25
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label3
 
 SWRS:
 mov eax, codes+30
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label4
 
 STRK:
 mov eax, codes+35
 call print_string
 mov eax, four_spaces
 call print_string
 jmp label4
 
 end:
 
 popa
 mov eax, 0
 leave
 ret