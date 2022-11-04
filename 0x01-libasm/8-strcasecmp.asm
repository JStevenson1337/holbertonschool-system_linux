BITS 64
	global asm_strcasecmp
	section .text

asm_strcasecmp:
	push rbp
	mov rbp, rsp
	push rdx

while:
	mov rax, rdi 				; rax = s1
	mov rdx, rsi				; rdx = s2
	movzx eax, BYTE [rax]		
	movzx edx, BYTE [rdx]
	cmp al, 0x0
	jne not_both_null
	cmp dl, 0x0
	je _L2
	not_both_null:
	cmp al, 65
	jl case_a_done
	cmp al, 90
	jg case_a_done
	add ax, 32
	case_a_done:
	cmp dl, 65
	jl _L1
	cmp dl, 90
	jg _L1
	add dx, 32

_L1:
	cmp al, dl
	jne _L2
	inc rdi
	inc rsi
	jmp while

_L2:
	cmp al, dl
	je equal
	jl less
	sub al, dl
	jmp _End
_isIS:
	mov rax, 0x0
	jmp _End
_lessThan:
	sub al, dl
	neg al
	imul eax, -1
	jmp _End

_End:
	pop rdx

	mov rbp, rsp
	pop rbp
	ret
