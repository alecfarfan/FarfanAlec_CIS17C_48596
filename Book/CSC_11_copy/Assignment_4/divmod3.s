/* divmod3.s */

.data

.balign 4
prompt: .asciz "Efficient technique for calculating a/b and a%b\n"
.balign 4
inputa: .asciz "Enter a:"
.balign 4
inputb: .asciz "Enter b:"
.balign 4
output1: .asciz "%d/%d is %d\n"
.balign 4
output2: .asciz "%d%%%d is %d\n"
.balign 4
formatd: .asciz "%d"
.balign 4
a: .word 0
.balign 4
b: .word 0
.balign 4
return: .word 0
.balign 4
return2: .word 0

.text
.global main
main:
	LDR R1, address_return
	STR LR, [R1]
	LDR R0, address_prompt
	BL printf
	LDR R0, address_inputa
	BL printf
	LDR R0, address_formatd
	LDR R1, address_a
	BL scanf

	LDR R0, address_inputb
	bl printf
	LDR R0, address_formatd
	LDR R1, address_b
	BL scanf

	LDR R0, address_a
	LDR R0, [R0]
	LDR R1, address_b
	LDR R1, [R1]
	BL divMod

	MOV R5, R1
	MOV R3, R0
	LDR R0, address_output1
	LDR R1, address_a
	LDR R1, [R1]
	LDR R2, address_b
	LDR R2, [R2]
	BL printf

	MOV R3, R5
	LDR R0, address_output2
	LDR R1, address_a
	LDR R1, [R1]
	LDR R2, address_b
	LDR R2, [R2]
	BL printf

	LDR LR, address_return
	LDR LR, [LR]
	BX LR

divMod:
	LDR R1, address_return2
	STR LR, [R1]
	LDR R2, address_a
	LDR R2, [R2]
	LDR R3, address_b
	LDR R3, [R3]
	MOV R4, #1
	MOV R5, R3
	MOV R0, #0
	MOV R1, R2

	CMP R1, R3
	BGE scaleLeft1
	BLT end

scaleLeft1:
	MOV R4, R4, LSL #1
	MOV R5, R5, LSL #1
	CMP R1, R5
	BGT scaleLeft1
	BLE scaleLeft2

scaleLeft2:
	MOV R4, R4, LSR #1
	MOV R5, R5, LSR #1
	BAL addSub1

scaleRight:
	MOV R4, R4, LSR #1
	MOV R5, R5, LSR #1
	CMP R1, R5
	BLT scaleRight
	BGE addSub2

addSub1:
	ADD R0, R0, R4
	SUB R1, R1, R5
	BAL scaleRight

addSub2:
	CMP R4, #1
	BGE addSub1
	BLT end

end:
	LDR LR, address_return2
	LDR LR, [LR]
	BX LR

address_a: .word a
address_b: .word b
address_formatd: .word formatd
address_prompt: .word prompt
address_inputa: .word inputa
address_inputb: .word inputb
address_output1: .word output1
address_output2: .word output2
address_return: .word return
address_return2: .word return2

.global printf
.global scanf
