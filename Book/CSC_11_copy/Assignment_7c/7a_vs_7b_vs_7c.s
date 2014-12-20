/* 7a_vs_7b_vs_7c.s */

.data
intF:.asciz "%dF\n"
intC: .asciz "%dC\n"
floatC: .asciz"%fC\n"
floatF: .asciz"%fF\n"
tResult: .asciz "Time to calculate:%d seconds\n"
F: .float 212
threetwo: .float 32
nine: .float 9
five: .float 5

.text

.global main
main:
	PUSH {R4, LR}
	LDR R0, address_intF
	MOV R1, #212
	BL printf

	MOV R0, #0
	BL time

	MOV R4, R0
	MOV R7, #0
	LDR R8, =1000000
	MOV R9, #0
	LDR R10, =20

divloop:
	MOV R1, #212
	SUB R1, R1, #32
	MOV R2, #5
	MUL R1, R2, R1
	MOV R2, #9
	BL divMod

	MOV R1, R0
	ADD R7, R7, #1
	CMP R7, R8
	BLT divloop

	MOV R7, #0
	ADD R9, R9, #1
	CMP R9, R10
	BLT divloop

outputDivMod:
	MOV R1, R0
	LDR R0, address_intC
	BL printf

	MOV R0, #0
	BL time
	MOV R5, R0
	LDR R0, address_tResult
	SUB R1, R5, R4
	BL printf

shifting:
	MOV R0, #0
	BL time
	MOV R4, R0
	MOV R7, #0
	MOV R9, #0

shiftloop:
	MOV R1, #212
	SUB R1, R1, #32
	LDR R6, =0x8e38f
	MUL R1, R6, R1
	ASR R1, #20
	ADD R7, R7, #1
	CMP R7, R8
	BLT shiftloop

	MOV R7, #0
	ADD R9, R9, #1
	CMP R9, R10
	BLT shiftloop

outputShifting:
	LDR R0, address_intC
	BL printf
	MOV R0, #0
	BL time

	SUB R1, R0, R4
	LDR R0, address_tResult
	BL printf

floating:
	MOV R0, #0
	BL time

	MOV R4, r0
	MOV R7, #0
	LDR R8, =1000000
	MOV R9, #0
	LDR R10, =20

	LDR R0, address_floatF
	LDR R1, address_F
	VLDR S14, [R1]
	VCVT.F64.F32 D3, S14
	VMOV R2, R3, D3
	BL printf

floatloop:
	LDR R1, address_F
	VLDR S12, [R1]
	LDR R2, address_threetwo
	VLDR S13, [R2]
	LDR R3, address_five
	VLDR S14, [R3]
	LDR R4, address_nine
	VLDR S15, [R4]

	VSUB.F32 S12, S12, S13
	VMUL.F32 S12, S14, S12
	VDIV.F32 S12, S12, S15
	VCVT.F64.F32 D0, S12

	ADD R7, R7, #1
	CMP R7, R8
	BLT floatloop

	ADD R9, R9, #1
	CMP R9, R10
	BLT floatloop

outputfloat:
	MOV R0, #0
	BL time

	MOV R5, R0
	SUB R5, R5, R4
	LDR R0, address_floatC
	VMOV R2, R3, D0
	BL printf

	LDR R0, address_tResult
	MOV R5, R4
	BL printf

	POP {R4, LR}
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
address_intF: .word intF
address_intC: .word intC
address_floatF: .word floatF
address_floatC: .word floatC
address_F: .word F
address_tResult: .word tResult
address_five: .word five
address_nine: .word nine
address_threetwo: .word threetwo
