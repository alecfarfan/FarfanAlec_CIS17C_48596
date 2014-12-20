/* Prob3.s */

.data
output: .asciz "%f\n"
.text
.global main
main:

	PUSH {R4, LR}

	MOV R4, #12
	MOV R5, #8

	VMOV S15, R4
	VMOV S17, R5

	VCVT.F32.S32 S16, S15
	VCVT.F32.S32 S18, S17

	VDIV.F32 S19, S16, S18
	VCVT.F64.F32 D1, S19

	LDR R0, =output
	VMOV R2, R3, D1
	BL printf

	POP {R4, LR}
	BX LR
