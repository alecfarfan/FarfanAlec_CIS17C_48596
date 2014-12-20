/*  prob2.s */

.data
prompt1: .asciz "Input the number of years 1-20\n"
prompt2: .asciz "Input the percentage of the interest rate (5%%-10%%)\n"
prompt3: .asciz "Input the present value $1000-5000\n"
prompt4: .asciz "Enter:"
result1: .asciz "year %d:"
result2: .asciz " value = $%f\n"
formatd: .asciz "%d"
year: .word 0
intRate: .word 0
pValue: .word 0
array: .skip 128

.text

.global Prob2
Prob2:
	PUSH {R4, LR}

getInput:
	LDR R0, address_prompt1
	BL printf
	LDR R0, address_prompt4
	BL printf
	LDR R0, address_formatd
	LDR R1, address_year
	BL scanf

	LDR R0, address_prompt2
	BL printf
	LDR R0, address_prompt4
	BL printf
	LDR R0, address_formatd
	LDR R1, address_intRate
	BL scanf

	LDR R0, address_prompt3
	BL printf
	LDR R0, address_prompt4
	BL printf
	LDR R0, address_formatd
	LDR R1, address_pValue
	BL scanf

set:
	MOV R4, #0
	LDR R1, address_year
	LDR R5, [R1]
	LDR R1, address_intRate
	LDR R1, [R1]
	ADD R1, R1, #100

	VMOV S0, R1
	VCVT.F32.S32 S14, S0
	MOV R1, #100
	VMOV S0, R1
	VCVT.F32.S32 S15, S0
	VDIV.F32 S0, S14, S15
	LDR R6, address_array
	
	LDR R1, address_pValue
	LDR R1, [R1]
	VMOV S15, R1
	VCVT.F32.S32 S14, S15

calculate:
	VMUL.F32 S15, S14, S0
	VMOV S14, S15
	VMOV R1, S14
	STR R1, [R6, R4, LSL #2]
	ADD R4, R4, #1
	CMP R4, R5
	BLT calculate
	MOV R4, #0
	MOV R7, #1

print:
	LDR R0, address_result1
	MOV R1, R7
	BL printf

	LDR R0, address_result2
	LDR R8, [R6, R4, LSL #2]
	VMOV S0, R8
	VCVT.F64.F32 D5, S0
	VMOV R2, R3, D5
	BL printf

	ADD R4, R4, #1
	ADD R7, R7, #1
	CMP R4, R5
	BLT print

end:
	POP {R4, LR}
	BX LR

address_prompt1: .word prompt1
address_prompt2: .word prompt2
address_prompt3: .word prompt3
address_prompt4: .word prompt4
address_formatd: .word formatd
address_result1: .word result1
address_result2: .word result2
address_year: .word year
address_intRate: .word intRate
address_pValue: .word pValue
address_array: .word array
