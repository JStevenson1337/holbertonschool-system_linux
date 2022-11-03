BITS 64
	global asm_strlen
	section .text

asm_strlen:           ; size_t asm_strlen(const char *str)
	push rbp            ; save the base pointer
	mov rbp, rsp        ; set the base pointer to the stack pointer
	mov rax, 0          ; set the return value to 0
	jmp nullCheck       ; jump to the loop check

mainLoop:             ; loop body
	inc rax             ; increment the return value
	inc rdi             ; increment the string pointer

nullCheck:
	cmp byte [rdi], 0   ; check if the current character is null
	jne mainLoop        ; if not, jump to the loop body

	mov rsp, rbp        ; set the stack pointer to the base pointer
	pop rbp             ; restore the base pointer
	ret                 ; return
