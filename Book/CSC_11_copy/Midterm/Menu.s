/* Menu for Midterm */

.data
inter1: .asciz "-------------------------CSC_11_MIDTERM-------------------------\n"
inter2: .asciz " Problem 1: Gross Pay, Problem 2: ISP, or Problem 3: Fibonacci  \n"
inter3: .asciz "----------------------------------------------------------------\n"
prompt: .asciz "Enter the number of the problem to execute program:"
format: .asciz "%d"
input: .word 0

.text
.global main
main:
	PUSH {LR}
	
start:
	LDR R0, address_inter1
	BL printf
	LDR R0, address_inter2
	BL printf
	LDR R0, address_inter3
	BL printf
	LDR R0, address_prompt
	BL printf

	LDR R0, address_format
	LDR R1, address_input
	BL scanf
	LDR R2, address_input
	LDR R2, [R2]

	CMP R2, #1
	BLEQ Problem_1
	BEQ start
	CMP R2, #2
	BLEQ Problem_2
	BEQ start
	CMP R2, #3
	BLEQ Problem_3
	BEQ start

end:
	POP {LR}
	BX LR

address_inter1: .word inter1
address_inter2: .word inter2
address_inter3: .word inter3
address_prompt: .word prompt
address_format: .word format
address_input: .word input
