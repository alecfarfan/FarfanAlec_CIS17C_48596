/* Problem 2 ISP Packages */

.data
.balign 4
prompt2: .asciz "Enter your subscription package (ex. a,b,c) :"
prompt21: .asciz "Enter the number of hours used:"
result2: .asciz "Total: %d\n"
result21: .asciz "Total: %d\n"
format2: .asciz "%s"
format21: .asciz "%d"
input_char: .word 0
input_int: .word 0

.text
.global Problem_2
Problem_2:

	PUSH {LR}
	MOV R9, #0
	LDR R0, address_prompt2
	BL printf
	LDR R0, address_format2
	LDR R1, address_input_char
	BL scanf

	LDR R4, address_input_char
	LDRB R4, [R4]

	LDR R0, address_prompt21
	BL printf
	LDR R0, address_format21
	LDR R1, address_input_int
	BL scanf
	
	LDR R5, address_input_int
	LDR R5, [R5]

	CMP R4, #97
	BLEQ sub_a
	CMP R4, #98
	BLEQ sub_b
	CMP R4, #99
	BLEQ sub_c

	BAL end
print2:
	MOV R1, R9
	LDR R0, address_result21
	BL printf
	BAL end
sub_a:
	CMP R5, #22
	BGT a_additional_2
	CMP R5, #11
	BGT a_additional
	BAL a_straight

	a_additional_2:
	SUB R6, R5, #22
	MOV R10, #6
	MUL R7, R6, R10
	ADD R9, R9, R7 
	SUB R5, R5, R6

	a_additional:
	SUB R6, R5, #11
	MOV R10, #3
	MUL R7, R6, R10
	ADD R9, R9, R7
	SUB R5, R5, R6

	a_straight:
	ADD R9, R9, #30
	BAL print2	

sub_b:
	CMP R5, #44
	BGT b_additional_2
	CMP R5, #22
	BGT b_additional
	BAL b_straight

	b_additional_2:
	SUB R6, R5, #44
	MOV R10, #4
	MUL R7, R6, R10
	ADD r9, R9, R7 
	SUB R5, R5, R6

	b_additional:
	SUB R6, R5, #22
	MOV R10, #2
	MUL R7, R6, R10
	ADD r9, R9, R7
	SUB R5, R5, R6

	b_straight:
	ADD R9, R9, #35
	BAL print2
sub_c:
	CMP R5, #66
	BGT c_additional_2
	CMP R5, #33
	BGT c_additional
	BAL c_straight

	c_additional_2:
	SUB R6, R5, #66
	MOV R10, #2
	MUL R7, R6, R10
	ADD r9, R9, R7 
	SUB R5, R5, R6

	c_additional:
	SUB R6, R5, #33
	MOV R10, #1
	MUL R7, R6, R10
	ADD r9, R9, R7
	SUB R5, R5, R6

	c_straight:
	ADD R9, R9, #40
	BAL print2

end:
	POP {LR}
	BX LR

address_prompt2: .word prompt2
address_prompt21: .word prompt21
address_result2: .word result2
address_result21: .word result21
address_format2: .word format2
address_format21: .word format21
address_input_char: .word input_char
address_input_int: .word input_int
