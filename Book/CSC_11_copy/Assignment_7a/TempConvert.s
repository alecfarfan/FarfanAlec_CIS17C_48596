/* TempConvert.s */

.data
prompt: .asciz "Enter a number in fahrenheit:";
formatd:.asciz "%d"
num: .word 0
result: .asciz "Celsius:%d\n"

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

	LDR R1, address_num
	LDR R1, [R1]
	SUB R1, R1, #32
	MOV R2, #5
	MUL R1, R2, R1
	MOV R2, #9
	BL divMod

	MOV R1, R0
	LDR R0, address_result
	BL printf

	BAL end

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
	CMP R3,#1
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
