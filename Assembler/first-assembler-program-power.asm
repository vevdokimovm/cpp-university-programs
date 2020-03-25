main:
    call power
power:
    push ecx
    push ebx
	
	
    mov ecx, 1
    mov ebx, edx
	
	
    loop :
    cmp ebx, 0
    jnz consequence
    jmp end
    consequence :
    imul ecx, eax
    dec ebx
    jmp loop

	
    end :
    pop ebx
    pop ecx
    ret
