/* Collatz.s */

.data
prompt: .asciz "Enter a number to calculate the length of its Collatz sequence: "
formatd: .asciz "%d"
result: .asciz "%d has %d steps in its Collatz sequence\n"
result2: .asciz "Calculated in %d seconds\n"
header1: .asciz "Branching solution\n"
header2: .asciz "Predicates solution\n"

.text

.global main
main:
	PUSH {LR}
	SUB SP, SP, #4

	LDR R0, address_prompt
 	BL printf

	LDR R0, address_formatd
 	MOV R1, SP
 	BL scanf

	MOV R0, #0
	BL time

	MOV R5, R0
	LDR R0, [SP]
 	BL collatz
	MOV R2, R0
	LDR R1, [SP]

	PUSH {R0, R1, R2, R3}
	LDR R0, address_header1
	BL printf
	POP {R0, R1, R2, R3}

	LDR R0, address_result
	BL printf

	MOV R0, #0
	BL time

	SUB R1, R0, R5
	LDR R0, address_result2
	BL printf

	MOV R0, #0
	BL time

	MOV R5, R0
	LDR R0, [SP]
	BL collatz2

	MOV R2, R0
	LDR R1, [SP]

	PUSH {R0, R1, R2, R3}
	LDR R0, address_header2
	BL printf
	POP {R0, R1, R2, R3}

	LDR R0, address_result
	BL printf

	MOV R0, #0
	BL time

	SUB R1, R0, R5
	LDR R0, address_result2
	BL printf

	ADD SP, SP, #4
	POP {LR}
	BX LR

collatz:
	PUSH {R4}
	SUB SP, SP, #4
	MOV R4, R0
	MOV R3, #4194304

collatz_repeat:
	MOV R1, R4
	MOV R0, #0

collatz_loop:
	CMP R1, #1
	BEQ collatz_end
	AND R2, R1, #1
	CMP R2, #0
	BNE collatz_odd

collatz_even:
	MOV R1, R1, ASR #1
	BAL collatz_end_loop

collatz_odd:
	ADD R1, R1, R1, LSL #1
	ADD R1, R1, #1

collatz_end_loop:
	ADD R0, R0, #1
	BAL collatz_loop

collatz_end:
	SUB R3, R3, #1
	CMP R3, #0
	BNE collatz_repeat
	ADD SP, SP, #4
	POP {R4}
	BX LR

collatz2:
	PUSH {R4}
	SUB SP, SP, #4
	MOV R4, R0
	MOV R3, #4194304

collatz2_repeat:
	MOV R1, R4
	MOV R0, #0

collatz2_loop:
	CMP R1, #1
	BEQ collatz_end
 	AND R2, R1, #1
 	CMP R2, #0
 	ADDNE R1, R1, R1, LSL #1
	ADDNE R1, R1, #1
	MOVEQ R1, R1, ASR #1

collatz2_end_loop:
	ADD R0, R0, #1
	BAL collatz2_loop

collatz2_end:
	SUB R3, R3, #1
	CMP R3, #0
	BNE collatz_repeat
	ADD SP, SP, #4
	POP {R4}
	BX LR

address_prompt: .word prompt
address_result: .word result
address_formatd: .word formatd
address_result2: .word result2
address_header1: .word header1
address_header2: .word header2
