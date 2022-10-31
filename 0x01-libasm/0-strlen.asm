BITS 64

global asm_strlen

asm_strlen:
	push rcx
	xor rcx, rcx

asm_strlen_cmp:
	cmp [rdx]: byte 0
	jz asm_strlen_end
	inc rcx
	inc rdx
	jmp asm_strlen_cmp
	
asm_strlen_end:
	mov rax, rcx
	pop rcxret
