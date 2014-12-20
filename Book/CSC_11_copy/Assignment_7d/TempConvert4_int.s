/* TempConvert4_int.s */

.data
array: .skip 2047
result: .asciz "Farhenheit:%d\n"

.text

.global main
main:
	PUSH {LR}
	LDR R7, =0x8e38f

fill:
	MOV R3, #32
	LDR R5, address_array
	MOV R11, #0

fillLoop:
	STR R3, [R5, R11, LSL #2]
	ADD R3, R3, #5
	ADD R11, R11, #1
	CMP R11, #37
	BLT fillLoop
	MOV R11, #0

printLoop:
	LDR R0, address_result
	LDR R1, [R5, R11, LSL #2]
	BL printf
	ADD R11, R11, #1
	CMP R11, #37
	BLT printLoop
	MOV R11, #0

convertLoop:
	LDR R3, [R5, R11, LSL #2]
	SUB R3, R3, #32
	MUL R3, R7, R3
	MOV R3, R3, ASR #20
	STR R3, [R5, R11, LSL #2]
	ADD R11, R11, #1
	CMP R11, #37
	BLT convertLoop
	MOV R11, #0

printConversions:
	LDR R1, [R5, R11, LSL #2]
	LDR R0, address_result
	BL printf
	ADD R11, R11, #1
	CMP R11, #37
	BLT printConversions

end:
	POP {LR}
	BX LR

address_array: .word array
address_result: .word result

