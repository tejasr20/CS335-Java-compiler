
section .text
	global main
L0:
L1:
	mov [ ebp - 12 ], dword 1
	mov eax, [ ebp - 12 ]
	mov ebx, eax
	inc eax
	mov [ ebp - 12 ], eax
	add eax, 2
	mov ecx, [ ebp - 12 ]
	sub ecx, 3
	mov edi, [ ebp - 12 ]
	imul edi, 4
	mov [ ebp - 20 ], eax
	mov eax, [ ebp - 12 ]
	mov esi, dword 2
	cdq
	idiv esi
	mov [ ebp - 32 ], eax
	mov [ ebp - 16 ], ebx
	mov [ ebp - 24 ], ecx
	mov [ ebp - 28 ], edi
L2:
