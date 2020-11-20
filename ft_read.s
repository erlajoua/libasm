			extern __errno_location
			section .txt
			global ft_read

ft_read:
			mov rax, 0
			syscall
			cmp rax, 0
			jl error_out
			ret

error_out:
			neg rax
			mov r10, rax
			call __errno_location
			mov [rax], r10
			mov rax, -1
			ret
