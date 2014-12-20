/* divMod.s */

.text

.global divMod
divMod:
	PUSH {LR}
	MOV R0, #0
	MOV R3, #1
	CMP R1, R2
	BLT end
	BL scaleLeft
	BL addSub
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

end:
	POP {LR}
	BX LR
