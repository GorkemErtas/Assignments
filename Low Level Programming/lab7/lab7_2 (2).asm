%include "asm_io.inc"


segment .data
L1 db "Enter an integer: ", 0
L2 db "Hex representation: ", 0

segment .bss

segment .text
global _asm_main
_asm_main:
enter 0,0
pusha

while:
mov eax, L1
call print_string
call read_int
mov ebx, eax
cmp eax, 0
je end_while
mov eax, L2
call print_string

mov ecx, 8
loop_start:
mov edx, 0
sal ebx,1
adc edx, 0
sal edx, 1
sal ebx,1
adc edx, 0
sal edx, 1
sal ebx,1
adc edx, 0
sal edx, 1
sal ebx,1
adc edx, 0
mov eax, edx
cmp eax, 9
jg print_hex_as_letter
call print_int
loop loop_start

call print_nl
jmp while

print_hex_as_letter:
sub eax, 10
add eax, 65
call print_char
sub ecx, 1
cmp ecx, 0
jg loop_start
call print_nl
jmp while

end_while:


popa
mov eax, 0
leave
ret