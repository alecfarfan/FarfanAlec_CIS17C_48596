/* TempConvert4_float.s */

.data

floatF: .asciz "Fahrenheit:%f\n"
floatC: .asciz "Celcius:%f\n"
array: .skip 1024
five: .float 5.0
nine: .float 9.0
threeTwo: .float 32.0

.text

.global main
main:
	PUSH {R4, LR}

	MOV R8, #32
	LDR R1, address_threeTwo
	VLDR S3, [R1]
	LDR R1, =five
	VLDR S9, [R1]
	LDR R1, =nine
	VLDR S31, [R1]
	LDR R6, address_array
	MOV R11, #0

fill:
	VMOV S0, R8
	VCVT.F32.S32 S1, S0
	VMOV R7, S1
	STR R7, [R6, R11, LSL #2]
	ADD R11, R11, #1
	ADD R8, R8, #5
	CMP R8, #212
	BLE fill

	MOV R11, #0

print1:
	LDR R1, [R6, R11, LSL #2]
	VMOV S14, R1
	VCVT.F64.F32 D5, S14
	VMOV R2, R3, D5
	LDR R0, address_floatF
	BL printf

	ADD R11, R11, #1
	CMP R11, #37
	BLT print1
	MOV R11, #0

convert:
	LDR R1, [R6, R11, LSL #2]
	VMOV S14, R1
	VSUB.F32 S14, S14, S3
	VMUL.F32 S14, S14, S9
	VDIV.F32 S14, S14, S31
	VMOV R1, S14
	STR R1, [R6, R11, LSL #2]
	ADD R11, R11, #1
	CMP R11, #37
	BLT convert

	MOV R11, #0

print2:
	LDR R1, [R6, R11, LSL #2]
	VMOV S14, R1
	VCVT.F64.F32 D5, S14
	VMOV R2, R3, D5
	LDR R0, address_floatC
	BL printf

	ADD R11, R11, #1
	CMP R11, #37
	BLT print2

	POP {R4, LR}
	BX LR

address_floatF: .word floatF
address_floatC: .word floatC
address_array: .word array
address_five: .word five
address_nive: .word nine
address_threeTwo: .word threeTwo
