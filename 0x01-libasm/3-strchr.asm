BITS 64
	global asm_strchr
	section text
asm_strchr:
	push rbp ; save the base pointer
	mov rbp, rsp ; set the base pointer to the stack pointer
	xor rax, rax ; clear the return value

mainLoop: ; loop until we find the character or reach the end of the string
	mov al, BYTE [rdi] ; get the current character
	cmp BYTE [rdi], sil ; compare it to the character we're looking for
	jz foundIT ; if it's the same, jump to the foundIT label
	cmp BYTE [rdi], 0 ; if it's the null terminator, jump to the endIT label
	jz end ; if it's the null terminator, jump to the endIT label
	inc rdi ; increment the string pointer
	jmp mainLoop ; jump back to the main loop

foundIT: ; if we found the character, set the return value to the string pointer
	mov rax, rdi ; set the return value to the string pointer

end: ; end of the function
	mov rsp, rbp ; restore the stack pointer
	pop rbp ; restore the base pointer
	ret ; return
