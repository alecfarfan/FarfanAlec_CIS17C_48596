/* 7a_vs_7b.s */

.data
prompt: .asciz "Enter a number in farhenheit:"
formatd: .asciz "%d"
num: .word 0
result: .asciz "Celsius:%d\n"
result2: .asciz "Time to calculate:%d seconds\n"

.text

.global main
main:
	PUSH {LR}

loop:
	LDR R0, address_prompt
	BL printf

	LDR R0, address_formatd
	LDR R1, address_num
	BL scanf

	LDR R1, address_num
	LDR R1, [R1]
	CMP R1, #32
	BLT loop

	LDR R1, address_num
	LDR R1,[R1]
	CMP R1, #212
	BGT loop

	MOV R0, #0
	BL time

	MOV R4, R0
	MOV R7, #0
	LDR R8, =1000000
	MOV R9, #0
	LDR R10, =20

divTime:
	LDR R1, address_num
	LDR R1, [R1]
	SUB R1, R1, #32
	MOV R2, #5
	MUL R1, R2, R1
	MOV R2, #9
	BL divMod

	MOV R1, R0
	ADD R7, R7, #1
	CMP R7, R8
	BLT divTime

	MOV R7, #0
	ADD R9, R9, #1
	CMP R9, R10
	BLT divTime

	MOV R1, R0
	LDR R0, address_result
	BL printf

	MOV R0, #0
	BL time

	MOV R5, R0
	LDR R0, address_result2
	SUB R1, R5, R4
	BL printf

	MOV R0, #0
	BL time

	MOV R4, R0
	MOV R7, #0
	MOV R9, #0

shifting:
	LDR R1, address_num
	LDR R1, [R1]
	SUB R1, R1, #32
	LDR R6, =0x8e38f
	MUL R1, R6, R1
	ASR R1, #20
	ADD R7, R7, #1
	CMP R7, R8
	BLT shifting

	MOV R7, #0
	ADD R9, R9, #1
	CMP R9, R10
	BLT shifting

	LDR R0, address_result
	BL printf

	MOV R0, #0
	BL time

	SUB R1, R0, R4
	LDR R0, address_result2
	BL printf

	POP {LR}
	BX LR

scaleRight:
	PUSH {LR}

scaleRloop:
	MOV R3, R3, ASR #1
	MOV R2, R2, ASR #1
	CMP R1, R2
	BLT scaleRloop
	BAL end

addSub:
	PUSH {LR}

addSubLoop:
	ADD R0, R0, R3
	SUB R1, R1, R2
	BL scaleRight
	CMP R3, #1
	BGE addSubLoop
	BAL end

scaleLeft:
	PUSH {LR}

scaleLloop:
	MOV R3, R3, LSL #1
	MOV R2, R2, LSL #1
	CMP R1, R2
	BGE scaleLloop
	MOV R3, R3, ASR #1
	MOV R2, R2, ASR #1
	BAL end

divMod:
	PUSH {LR}

	MOV R0, #0
	MOV R3, #1
	CMP R1, R2
	BLT end
	BL scaleLeft
	BL addSub

end:
	POP {LR}
	BX LR

address_prompt: .word prompt
address_formatd: .word formatd
address_num: .word num
address_result: .word result
address_result2: .word result2
