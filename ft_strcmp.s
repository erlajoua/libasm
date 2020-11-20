			section .txt
			global ft_strcmp

;int	ft_strcmp(char *s1, char *s2

ft_strcmp:
			mov r9, 0
			mov dl, 0 ;petit bout 0
			mov al, 0 ;petit bout 0
main:
			mov dl, BYTE[rdi + r9]
			mov al, BYTE[rsi + r9]

			cmp dl, 0
			je out
			cmp al, 0
			je out
			cmp dl, al
			jne out
			inc r9
			jmp main

out:
			movzx rax, al
			movzx rdx, dl
			sub rax, rdx
			ret
