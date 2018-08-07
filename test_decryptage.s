;	zone: 0x11111111
;	zone_size: 0x22222222
;	key: 0x33333333
;	jmp to real text section: 0x4444444
;	zone to mprotect: 0x555555
;	size of this zone: 0x666666666

section .text
	global _start
	global _decrypt

_start:
	push rbp
	mov rbp, rsp

	mov rax, 0xa
	mov rdi, 0x5555555555555555
	mov rsi, 0x6666666666666666
	mov rdx, 0x7
	syscall
	call _print_str
	call _decrypt
	mov rax, 0x4444444444444444
	pop rbp
	jmp rax

_print_str:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov rdi, 0x00000a2e2e2e2e59
	push rdi
	mov rdi, 0x444f4f572e2e2e2e
	push rdi
	mov rdi, 1
	mov rsi, rsp
	mov rdx, 14
	mov rax, 1
	syscall
	pop rdi
	pop rdi
	leave
	ret

_decrypt:
	push rbp
	mov rbp, rsp
	sub rsp, 0x490 ;0x12c
	xor rcx, rcx

_init_table:
	cmp rcx, 0x100
	jge _init_sorting
;    xor r10, r10
	mov r10, 4
;    xor rax, rax
	mov rax, rcx
	mul r10
	mov DWORD [rsp + rax], ecx
	inc rcx
	jmp _init_table

_init_sorting:
	xor rcx, rcx
;	mov r10, QWORD [rsp + 1040]
	mov QWORD [rsp + 1040], 0

_sorting:
	cmp rcx, 0x100
	jge _init_decrypt_loop
;    xor r12, r12
	mov r12, 4
;    xor rax, rax
	mov rax, rcx
	mul r12
	xor r10, r10
	mov r10d, DWORD [rsp + rax]
	add QWORD [rsp + 1040], r10
;    xor r11, r11
	mov r11, 0x3333333333333333
	xor r10, r10
	mov r10b, BYTE [r11 + rcx]
	add QWORD [rsp + 1040], r10
	and QWORD [rsp + 1040], 255
	lea rdi, [rel rsp + rax]
	xor r10, r10
	mov r10b, BYTE [rsp + 1040]
	xor rax, rax
;    xor r12, r12
	mov r12, 4
	mov rax, r10
	mul r12
	lea rsi, [rel rsp + rax]

_swap:
	xor r10, r10
	xor r11, r11
	mov r10d, DWORD [rdi]
	mov r11d, DWORD [rsi]
	add DWORD [rdi], r11d
	mov r10d, DWORD [rdi]
	sub r10, r11
	mov DWORD [rsi], r10d
	mov r11d, DWORD [rsi]
	sub DWORD [rdi], r11d
	inc rcx
	jmp _sorting

_init_decrypt_loop:
;	xor r10, r10
;	mov r10, QWORD [rsp + 1040]
	mov QWORD [rsp + 1040], 0
;	xor r10, r10
;	mov r10, QWORD [rsp + 1048]
	mov QWORD [rsp + 1048], 0
	xor rcx, rcx

_decrypt_loop:
;    xor r10, r10
	mov r10, 0x2222222222222222
	cmp rcx, r10
	jge _end
	add QWORD [rsp + 1040], 1
	and QWORD [rsp + 1040], 255
;	xor r10, r10
	mov r10, QWORD [rsp + 1040]
;    xor r12, r12
;    xor rax, rax
	mov r12, 4
	mov rax, r10
	mul r12
	lea rdi, [rel rsp + rax]
	xor r10, r10
	mov r10d, DWORD [rdi]
	add QWORD [rsp + 1048], r10
	and QWORD [rsp + 1048], 255
;	xor r10, r10
	mov r10, QWORD [rsp + 1048]
;    xor r12, r12
;    xor rax, rax
	mov r12, 4
	mov rax, r10
	mul r12
	lea rsi, [rel rsp + rax]

_swap2:
	xor r10, r10
	xor r11, r11
	mov r10d, DWORD [rdi]
	mov r11d, DWORD [rsi]
	add DWORD [rdi], r11d
	mov r10d, DWORD [rdi]
	sub r10, r11
	mov DWORD [rsi], r10d
	mov r11d, DWORD [rsi]
	sub DWORD [rdi], r11d

_continue:
;    xor r10, r10
;	mov r10, QWORD [rsp + 1048]
	mov QWORD [rsp + 1048], 0
	xor r10, r10
	mov r10d, DWORD [rdi]
	xor r11, r11
	mov r11d, DWORD [rsi]
	add QWORD [rsp + 1048], r10
	add QWORD [rsp + 1048], r11
	and QWORD [rsp + 1048], 255
;	xor r11, r11
	mov r11, QWORD [rsp + 1048]
;    xor r12, r12
;    xor rax, rax
	mov r12, 4
	mov rax, r11
	mul r12
	xor r10, r10
	mov r10d, DWORD [rsp + rax]
;    xor r11, r11
	mov r11, 0x1111111111111111
	xor BYTE [r11 + rcx], r10b
	inc rcx
	jmp _decrypt_loop

_end:
	leave
	ret
