/* Prob1.s */

.data
prompt1: .asciz "I have a number between 1 and 1000\nCan you gess my number?\nYou will be given a maximum of 10 guesses.\n"
prompt2: .asciz "Please type your guess.\n"
prompt3: .asciz "%d.) Enter:"
prompt4: .asciz "Enter:"
pFound: .asciz "Congratulations, You guessed the number!\n"
pLow: .asciz "Too low. Try again.\n"
pHigh: .asciz "Too High. Try again.\n"
pOver: .asciz "Too many tries.\n"
pDone: .asciz "Too many tries.\n"
pAgain: .asciz "Would you like to play again(y or n)?\n"
invalid: .asciz "Error. Invalid Choice.\n"
formats: .asciz "%s"
formatd: .asciz "%d"
num: .word 0
choice: .word 0

.text

.global Prob1
Prob1:
	PUSH {R4, LR}

start:
	MOV R4, #1
	MOV R0, #0
	BL time
	BL srand
	BL rand

	MOV R1, R0
	MOV R2, #1000
	BL divMod
	MOV R5, R1
	LDR R0, address_prompt1
	BL printf

loop:
	LDR R0, address_prompt2
	BL printf
	LDR R0, address_prompt3
	MOV R1, R4
	BL printf

	LDR R0, address_formatd
	LDR R1, address_num
	BL scanf

	LDR R1, address_num
	LDR R1, [R1]
	MOV R2, R5

	CMP R1, R2
	BEQ correct
	BGT high
	BLT low

high:
	LDR R0, address_pHigh
	BL printf
	BAL check

low:
	LDR R0, address_pLow
	BL printf
	BAL check

correct:
	LDR R0, address_pFound
	BL printf	
	BAL playAgain

check:
	ADD R4, R4, #1
	CMP R4, #11
	BNE loop
	LDR R0, address_pDone
	BL printf
	BAL playAgain

playAgain:
	LDR R0, address_pAgain
	BL printf
	LDR R0, address_prompt4
	BL printf

	LDR R0, address_formats
	LDR R1, address_choice
	BL scanf

	LDR R1, address_choice
	LDRB R1, [R1]
	CMP R1, #'y'
	BEQ start

	LDR R1, address_choice
	LDRB R1, [R1]
	CMP R1, #'n'
	BEQ end

	LDR R0, address_invalid
	BL printf
	BAL playAgain

end:
	POP {R4, LR}
	BX LR

address_prompt1: .word prompt1
address_prompt2: .word prompt2
address_prompt3: .word prompt3
address_prompt4: .word prompt4
address_pFound: .word pFound
address_pLow: .word pLow
address_pHigh: .word pHigh
address_pOver: .word pOver
address_pDone: .word pDone
address_pAgain: .word pAgain
address_invalid: .word invalid
address_formatd: .word formatd
address_formats: .word formats
address_num: .word num
address_choice: .word choice
