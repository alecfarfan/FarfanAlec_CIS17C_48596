/* Factorial_2.s */
.data
 
prompt: .asciz "Enter a number to calculate the factorial:"
formatd:   .asciz "%d"
result: .asciz "The factorial of %d is %d\n"
 
.text

.global main
main:
    STR LR, [SP,#-4]!
    SUB SP, SP, #4
    LDR R0, address_prompt
    BL printf

    LDR R0, address_formatd
    MOV R1, SP
    BL scanf
 
    LDR R0, [SP]
    BL factorial
    MOV R2, R0
    LDR R1, [SP]
    LDR R0, address_result
    BL printf

    ADD SP, SP, #+4
    LDR LR, [SP], #+4
    BX LR
 
factorial:
    STR LR, [SP,#-4]!
    STR R4, [SP,#-4]!
    MOV R4, R0
    CMP R0, #0
    BNE is_nonzero
    MOV R0, #1
    BAL end

is_nonzero:
    SUB R0, R0, #1
    BL factorial
    MOV R1, R4
    MUL R0, R1, R0
 
end:
    LDR R4, [SP], #+4
    LDR LR, [SP], #+4
    BX LR

address_prompt: .word prompt
address_result: .word result
address_formatd: .word formatd
