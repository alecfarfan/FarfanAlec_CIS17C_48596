/* Prob3.s */

.data
prompt1: .asciz "Newton's method of calculating square roots\n"
prompt2: .asciz "Enter an integer between 1 and 10000\n"
prompt3: .asciz "Enter:"
formatd: .asciz "%d"
num: .word 0
preResult: .asciz "%f\n"
result: .asciz "square root is %f\n"
pInvalid: .asciz "Error. Number must be 1-10000\n"
oneDigit: .float 100
twoDigit: .float 200
threeDigit: .float 300
fourDigit: .float 400
fiveDigit: .float 500
two: .float 2
tenK: .word 10000

.text

.global Prob3
Prob3:
	PUSH {R4, LR}

	LDR R0, address_prompt1
	BL printf

	LDR R0, address_prompt2
	BL printf

getInput:	

	LDR R0, address_prompt3
	BL printf

	LDR R0, address_formatd
	LDR R1, address_num
	BL scanf

	LDR R1, address_num
	LDR R1, [R1]
	CMP R1, #1
	BLLT invalid
	BLT getInput

	CMP R1, #10
	LDRLT R1, address_oneDigit
	BLT set

	CMP R1, #100
	LDRLT R1, address_twoDigit
	BLT set

	CMP R1, #1000
	LDRLT R1, address_threeDigit
	BLT set

	LDR R0, address_tenK
	CMP R1, R0
	LDRLT R1, address_fourDigit
	LDREQ R1, address_fiveDigit
	BLE set
	BLGT invalid
	BGT getInput

set:
	VLDR S12, [R1]
	LDR R1, address_two
	VLDR S13, [R1]
	LDR R1, address_num
	LDR R1, [R1]
	VMOV S14, R1

	VCVT.F32.S32 S15, S14
	VCVT.F64.F32 D0, S15

	BAL calculate

calculate:
	VMOV S16, S12
	VDIV.F32 S17, S15, S12
	VCVT.F64.F32 D0, S17
	LDR R0, address_preResult
	VMOV R2, R3, D0
	BL printf

	VADD.F32 S12, S12, S17
	VDIV.F32 S12, S12, S13

	VMOV R1, S16
	VMOV R2, S12
	CMP R1, R2
	BNE calculate
	BAL print

print:
	VCVT.F64.F32 D4, S12
	LDR R0, address_result
	VMOV R2, R3, D4
	BL printf

	BAL end

end:
	POP {R4, LR}
	BX LR

invalid:
	PUSH {LR}

	LDR R0, address_pInvalid
	BL printf

	POP {LR}
	BX LR

address_prompt1: .word prompt1
address_prompt2: .word prompt2
address_prompt3: .word prompt3
address_formatd: .word formatd
address_num: .word num
address_preResult: .word preResult
address_result: .word result
address_pInvalid: .word pInvalid
address_oneDigit: .word oneDigit
address_twoDigit: .word twoDigit
address_threeDigit: .word threeDigit
address_fourDigit: .word fourDigit
address_fiveDigit: .word fiveDigit
address_two: .word two
address_tenK: .word tenK
