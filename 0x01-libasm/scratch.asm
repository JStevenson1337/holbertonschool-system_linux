64 BITS

globl my_function  ; EXPORT function 'test'
extern this_function  ; IMPORT the function 'second_function'

section .data
    ; Declare static data
  my_str db "Holberton", 0Ah, 0
  ; "Holberton", followed by a mew line (0A hexa), and \0


section .text

    ; Code section

my_function:    ; This is a symbol
  ; Do some
  ; some
  ; stuff
  ; here

;; COMPILE ;;
; nasm -f elf64 example+0.asm


