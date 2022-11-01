BITS 64

section .data

section .text
	global _start

_start:


	mov rax, 1 ; move into rax the value 1
	cmp rax, 0 ; compare rax with 0
	jne .addOneByte ; if rax is not equal to 0, jump to .addOneByte
	je .printNumBytes ; if rax is equal to 0, jump to .printNumBytes
	mov rax, 0 ; move into rax the value 0
	mov rdi, 1 ; move into rdi the value 1
	mov rsi, .numBytes ; move into rsi the address of .numBytes
	mov rdx, 2 ; move into rdx the value 2
	syscall ; call the system call write
	mov rax, 60 ; move into rax the value 60
	mov rdi, 0 ; move into rdi the value 0

	syscall ; call the system call exit

.addOneByte: ; add 1 to the value of rax
	add byte [rsi], 1 ; add 1 to the byte pointed by rsi
	jmp .start ; jump to .start

.printNumBytes: ; print the number of bytes
	mov rax, 1 ; move into rax the value 1
	mov rdi, 1 ; move into rdi the value 1
	mov rsi, .numBytes ; move into rsi the address of .numBytes
	mov rdx, 2 ; move into rdx the value 2
	syscall ; call the system call write
	mov rax, 60 ; move into rax the value 60
	mov rdi, 0 ; move into rdi the value 0
	syscall ; call the system call exit


.numBytes: ; the number of bytes
	[]



