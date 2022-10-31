BITS 64

global asm_strlen

asm_strlen:
	push rcx
	xor rcx, rcx

asm_strlen_loop:
	cmp [rdi], byte 0
	jz asm_strlen_end

	inc rcx
	inc rdi
	jmp asm_strlen_loop

asm_strlen_end:
	mov rax, rcx
	pop rcx

	ret
