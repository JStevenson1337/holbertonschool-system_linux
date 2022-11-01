section .data
         text1 db "What is your name? "
		 text2 db "Hello"    ;db = define bytes lable string as text

section .text  ;lable for memory address of text to pass in
         global _start
_start:
         call _printText1
		 call _getName
		 call _printText2
         call _printName

         mov rax, 1
		 mov rdi, 1
		 mov rsi, text
		 mov rdx, 14
		 syscall

		 mov rax, 60 ;60 id for exit syscall
		 mov rdi, 0
		 syscall

_getName:
         mov rax, 0
		 mov rdi, 0
		 mov rsi, name
		 mov rdx, 16
		 syscall
		 ret
_printText1:
         mov rax, 1
		 mov rdi, 1
		 mov rsi, 1
		 mov rdx, 14
		 syscall
         ret

_printText2:
         mov rax, 1
		 mov rdi, 1
		 mov rdi, 1
		 mov rdx, 7
		 syscall
		 ret

_printName:
         mov rax, 1
		 mov rdi, 1
		 mov rsi, name
		 mov rdx, 16
		 syscall
		 ret
