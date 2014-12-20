/* Mod.s */

.data
prompt1: .asciz "Enter the numerator:"
prompt2: .asciz "Enter the denominator:"
numerator: .word 0 
denominator: .word 0
format: .asciz "%d"
divoutput: .asciz "Div:%d \n"
modoutput: .asciz "Mod:%d \n"

.text
.global main
main:

	PUSH {LR}
	
	LDR R0, address_prompt1
	BL printf
	LDR R0, address_format
	LDR R1, address_numerator
	BL scanf
	LDR R4, address_numerator
	LDR R4, [R4]

	LDR R0, address_prompt2
	BL printf
	LDR R0, address_format
	LDR R1, address_denominator
	BL scanf
	LDR R5, address_denominator
	LDR R5, [R5]
	
	MOV R6, #0
	BAL check

subtract:
	ADD R6, R6, #1
	SUB R4, R4, R5
check: 
	CMP R4, R5
	BGE subtract 

	LDR R0, address_divoutput
	MOV R1, R6
	BL printf
	
	LDR R0, address_modoutput
	MOV R1, R4
	BL printf

end:
	POP {LR}
	BX LR

address_prompt1: .word prompt1
address_prompt2: .word prompt2
address_numerator: .word numerator
address_denominator: .word denominator
address_format: .word format
address_divoutput: .word divoutput
address_modoutput: .word modoutput
