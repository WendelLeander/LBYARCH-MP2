section .data
converter dd 0.2777778

section .text
bits 64
default rel
global computeAcceleration


computeAcceleration:
    ; matrix@rax, num_cars@rdx, output@r8
    xor r9, r9                  
    L1:
        cmp r9, rdx                
        jge FINISH                   
    
        
        mov rax, r9               
        imul rax, 12                
        movss xmm0, dword [rcx + rax]      
        movss xmm1, dword [rcx + rax + 4]  
        movss xmm2, dword [rcx + rax + 8]  
    
        
        subss xmm1, xmm0    
        mulss xmm1, [converter]
        divss xmm1, xmm2    
    
        
        cvtss2si eax, xmm1           
        mov [r8 + r9*4], eax         
    
        inc r9
        jmp L1

    FINISH:
        ret
