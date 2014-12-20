/* TempConvert3.s */

.data
prompt: .asciz "Enter a number in fahrenheit:"
formatf: .asciz "%f"
num: .word 0
result: .asciz "Celcius:%f\n"
threetwo: .float 32
five: .float 5
nine: .float 9

.text

.global main
main:
	PUSH {R4, LR}

	LDR R0, address_prompt
	BL printf

	LDR R0, address_formatf
	LDR R1, address_num
	BL scanf

	LDR R1, address_num
	VLDR S12, [R1]
	LDR R2, address_threetwo
	VLDR S13, [R2]
	LDR R3, address_five
	VLDR S14, [r3]
	LDR R4, address_nine
	VLDR S15, [R4]

	VSUB.F32 S12, S12, S13
	VMUL.F32 S12, S14, S12
	VDIV.F32 S12, S12, S15
	VCVT.F64.F32 D0, S12

	LDR R0, address_result
	VMOV R2, R3, D0
	BL printf

	POP {R4, LR}
	BX LR

address_prompt: .word prompt
address_formatf: .word formatf
address_num: .word num
address_result: .word result
address_threetwo: .word threetwo
address_five: .word five
address_nine: .word nine
