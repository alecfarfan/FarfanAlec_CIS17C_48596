/* Problem 3 Fibonacci */
.data

prompt: .asciz "Enter a number to see that term of the fibonacci sequence:"
result: .asciz "Result: %d\n"
format: .asciz "%d"
input: .word 0
return: .word 0

.text

.global Problem_3
Problem_3:

	PUSH {LR}
getInput:
	LDR R0, address_prompt
	BL printf

	LDR R0, address_format
	LDR R1, address_input
	BL scanf

	MOV R3, #0
	MOV R4, #1
	MOV R5, #1
	LDR R6, address_input
	LDR R6, [r6]

	CMP R6, #0
	BEQ first
	CMP R6, #1
	BEQ second

	BAL check
first:
	MOV R7, #0
	BAL print
second:
	MOV r7, #1
	BAL print
fibonacci:
	ADC R7, R3, R4
	MOV R0, R7
	MOV R3, R4
	MOV R4, R7
	ADD R5, #1
check:
	CMP R5, R6
	BNE fibonacci
print:
	MOV R1, R7
	LDR R0, address_result
	BL printf
end:
	POP {lr}
	BX lr

address_prompt: .word prompt
address_result: .word result
address_format: .word format
address_input: .word input
address_return: .word return
