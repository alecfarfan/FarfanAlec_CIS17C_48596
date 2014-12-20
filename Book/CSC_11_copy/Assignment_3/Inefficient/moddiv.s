/* moddiv.s */

.global main
main:
	MOV R2, #111
	MOV R3, #5
	MOV R4, #0
	MOV R0, #0
	MOV R1, R2
	CMP R1, R3
	BGE subtract
	BLT swapCheck

subtract:
	ADD R0, R0, #1
	SUB R1, R1, R3
	CMP R1, R3
	BGE subtract
	BGT swapCheck

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
