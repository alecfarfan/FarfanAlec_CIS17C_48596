/* moddiv.s */

.global main
main:

	MOV R2, #22222
	MOV R3, #5
	MOV R4, #0
	MOV R5, #0
	MOV R6, #0
	MOV R7, #0
	MOV R8, #10
	MOV R9, #0
	MOV R0, #0
	MOV R1, R2
	BAL moddiv1

moddiv1:
	CMP R1, R3
	BGE scale
	BLT swapCheck

scale:
	MOV R6, #1
	MUL R7, R3, R6
	MUL R9, R7, R8
	CMP R1, R9
	BGT shift
	BLE moddiv2

shift:
	MUL R5, R6, R8
	MUL R6, R5
	MUL R7, R3, R6
	MUL R9, R7, R8
	BAL moddiv2

moddiv2:
	ADD R0, R0, R6
	SUB R1, R1, R7
	CMP R1, R7
	BGE moddiv2
	BLT check

check:
	CMP R6, #1
	BGT scale
	BLE swapCheck

swapCheck:
	CMP R4, #0
	BEQ swap
	BNE end

swap:
	MOV R5, R0
	MOV R0, R1
	MOV R1, R5
	BAL end

end:
	BX LR
