				segment .text
				global ft_strlen

ft_strlen:
				mov rax, 0

loop:
				cmp BYTE [rdi + rax], 0
				je out
				inc rax
				jmp loop

out:
				ret	
