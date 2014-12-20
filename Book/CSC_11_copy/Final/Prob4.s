/* Prob4.s */

.data
prompt: .asciz "find ax^2+bx\nPlease input a number between 0 and 255\n"
formatd: .asciz "%d"
num: .word 0
result: .asciz "ax^2+bx = %d\n"

.text

.global Prob4
Prob4:
	PUSH {R4, LR}

	LDR R0, address_prompt
	BL printf
	LDR R0, address_formatd
	LDR R1, address_num
	BL scanf

	LDR R1, =0x12b02
	LDR R2, =0xe04188
	LDR R3, address_num
	LDR R3, [R3]

	MUL R0, R1, R3
	MOV R0, R0, ASR #4
	MUL R0, R3, R0
	MUL R2, R3, R2
	MOV R2, R2, ASR #8
	ADD R0, R0, R2
	MOV R1, R0, ASR #16
	LDR R0, address_result
	BL printf

	POP {R4, LR}
	BX LR

address_prompt: .word prompt
address_formatd: .word formatd
address_num: .word num
address_result: .word result
