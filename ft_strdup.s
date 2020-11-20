			extern ft_strlen
			extern ft_strcpy
			extern malloc
			section .txt
			global ft_strdup

ft_strdup:
			push rdi 
			call ft_strlen 
			inc rax
			mov rdi, rax
			call malloc
			pop rsi
			mov rdi, rax
			call ft_strcpy
			ret
