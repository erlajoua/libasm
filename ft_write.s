			extern __errno_location
			global ft_write
			section .txt

ft_write:
			mov rax, 1
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
