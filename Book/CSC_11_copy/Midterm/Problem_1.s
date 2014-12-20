/* Problem 1 Gross Pay */
.data

prompt1: .asciz "Enter the number of hours worked (60 maximum) :"
prompt11: .asciz "Enter the rate of pay:"
result1: .asciz "Total: %d\n"
format1: .asciz "%d"
input1: .word 0
input11: .word 0
return1: .word 0

.text

.global Problem_1
Problem_1:
	PUSH {LR}
getInput:
	LDR R0, address_prompt1
	BL printf
	LDR R0, address_format1
	LDR R1, address_input1
	BL scanf

	LDR R4, address_input1
	LDR R4, [R4]
	CMP R4, #60
	BGT getInput

	LDR R0, address_prompt11
	BL printf
	LDR R0, address_format1
	LDR R1, address_input11
	BL scanf

	LDR R5, address_input11
	LDR R5, [r5]

	BAL pay
	BAL end

print1:
	MOV R1, R9
	LDR R0, address_result1
	BL printf
	BAL end
pay:
	CMP R4, #40
	BGT p_additional_2
	CMP R4, #20
	BGT p_additional
	BAL p_straight

	p_additional_2:
	SUB R6, R4, #40
	MOV R11, #3
	MUL R8, R11, R6
	MUL R7, R8, R5
	ADD r9, R9, R7
	SUB R4, R4, R6
        
	p_additional:
	SUB R6, R4, #20
	MOV R11, #2
	MUL R8, R11, R6
	MUL R7, R8, R5
	ADD R9, R9, R7
	SUB R4, R4, R6

	p_straight:
	MUL R10, R4, R5
	ADD R9, R9, R10
	BAL print1

end:
	POP {LR}
	BX LR

address_prompt1: .word prompt1
address_prompt11: .word prompt11
address_result1: .word result1
address_format1: .word format1
address_input1: .word input1
address_input11: .word input11
address_return1: .word return1
