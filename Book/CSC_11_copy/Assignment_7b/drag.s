/* drag.s */

.data
prompt1: .asciz"Enter the velocity:"
prompt2: .asciz"Enter the radius:"
formatd: .asciz "%d"
result1: .asciz "Integer Dynamic Pressure:%d lbs\n"
result2:.asciz"Cross Sectional Area*32:%d fit^2\n"
result3: .asciz "Integer Drag*32:%d lbs\n"
velocity: .word 0
radius: .word 0

.text
	
.global main
main:
	PUSH {LR}

	LDR R0, address_prompt1
	BL printf

	LDR R0, address_formatd
	LDR R1, address_velocity
	BL scanf

	LDR R0, address_prompt2
	BL printf

	LDR R0, address_formatd
	LDR R1, address_radius
	BL scanf

	MOV R3, #1
	LDR R4, =0x9b5
	LDR R5, address_velocity
	LDR R5, [R5]
	LDR R6, =0x3243f7

	LDR R7, address_radius
	LDR R7, [R7]
	LDR R8, =0x1c7
	LDR R9, =0x666

	MUL R3, R4, R3
	MUL R3, R5, R3
	MUL R3, R5, R3
	ASR R3, #12

	MUL R6, R7, R6
	MUL R6, R7, R6
	ASR R6, #12

	MUL R6, R8, R6
	ASR R6, #16
	MUL R10, R3, R6
	ASR R10, #12
	MUL R10, R9, R10

	ASR R3, #9
	ASR R6, #3
	ASR R10, #12

	LDR R0, address_result1
	MOV R1, R3
	BL printf

	LDR R0, address_result2
	MOV R1, R6
	BL printf

	LDR R0, address_result3
	MOV R1, R10
	BL printf


	POP {LR}
	BX LR

address_prompt1: .word prompt1
address_prompt2: .word prompt2
address_formatd: .word formatd
address_result1: .word result1
address_result2: .word result2
address_result3: .word result3
address_velocity: .word velocity
address_radius: .word radius
