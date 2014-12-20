/* CSC11 Final */
/* Menu.s */

.data
output1: .asciz "-------------------------CSC11 Final-------------------------\n"
output2: .asciz "Enter a number to execute the corresponding program\n"
output3: .asciz "or enter anything else to exit the menu\n"
p1: .asciz "Problem 1. Guessing Game\n"
p2: .asciz "Problem 2. Future Value\n"
p3: .asciz "Problem 3. Newton's Method\n"
p4: .asciz "Problem 4. Quadratics\n"
prompt: .asciz "Enter:"
formatd: .asciz "%d"
choice: .word 0

.text

.global main
main:
	PUSH {R4, LR}

menu:
	LDR R0, address_output1
	BL printf
	LDR R0, address_output2
	BL printf
	LDR R0, address_output3
	BL printf

	LDR R0, address_p1
	BL printf
	LDR R0, address_p2
	BL printf
	LDR R0, address_p3
	BL printf
	LDR R0, address_p4
	BL printf
	LDR R0, address_prompt
	BL printf

	LDR R0, address_formatd
	LDR R1, address_choice
	BL scanf

	LDR R1, address_choice
	LDR R1, [R1]
	CMP R1, #1
	BLEQ Prob1
	BEQ menu

	CMP R1, #2
	BLEQ Prob2
	BEQ menu

	CMP R1, #3
	BLEQ Prob3
	BEQ menu

	CMP R1, #4
	BLEQ Prob4
	BEQ menu

	BNE end

end:
	POP {R4, LR}
	BX LR

address_output1: .word output1
address_output2: .word output2
address_output3: .word output3
address_p1: .word p1
address_p2: .word p2
address_p3: .word p3
address_p4: .word p4
address_prompt: .word prompt
address_choice: .word choice
address_formatd: .word formatd
