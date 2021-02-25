				section .txt
				global ft_strcpy

ft_strcpy:
				mov dh, 0
				mov rax, 0

loop:
				cmp BYTE[rsi + rax], 0
				je out
				mov dh, BYTE [rsi + rax]
				mov BYTE [rdi + rax], dh
				inc rax
				jmp loop

out:
				mov BYTE[rdi + rax], 0
				mov rax, rdi
				ret
