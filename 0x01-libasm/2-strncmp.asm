BITS 64
	global asm_strncmp
	section .text

asm_strncmp
	push rbp
	mov rbp, rsp
	push rcx

_Loop:
	mov rax, rdi
	mov rcx, rsi
	movzx eax, BYTE [rax]
	movzx ecx, BYTE [rcx]
	cmp al, 0x0
	je _L1
	cmp al, cl
	jne _L1
	inc rdi
	inc rsi
	dec edx
	jz _Is
	jmp _Loop

_L1:
	cmp al, cl
	je _Is
	jl _Lt
	mov RAX, 0x1
	jmp _end
_Is:
	mov RAX, 0x0
	jmp _end
_Lt:
	mov RAX, -0x1
	jmp _end

_end:
	pop rcx

	mov rbp, rsp
	pop rbp
	ret
