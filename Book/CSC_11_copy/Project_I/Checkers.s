/* array.s */

.data
a: .skip 64
h: .asciz "--------\n"
under: .asciz "___________________________________     _________________________\n"
header: .asciz "   | A | B | C | D | E | F | G | H |   | Player 1 * | Player 2 o |\n"
b1: .asciz "___|___|___|___|___|___|___|___|___|   |     %d      |      "
b2: .asciz "   |____________|____________|"
endb1: .asciz "%d     |\n"
border: .asciz "___|___|___|___|___|___|___|___|___|\n"
format: .asciz "%s"
format1: .asciz "%d"
format2: .asciz " %c |"
format3: .asciz "%c"
formatd: .asciz "%d  |"
inputd: .asciz "%d"
endl: .asciz "\n"
choicePrompt1: .asciz "Enter the letter/number coordinate to select a gamepiece:"
choicePrompt2: .asciz "Enter the letter/number coordinate to move to that square:"
choice: .word 0
player: .asciz "Player %d\n"
invalid1: .asciz "Error. Must select one's own gamepiece\n"
invalid2: .asciz "Error. Illegal choice of movement\n"
invalid3: .asciz "Error. Illegal choice of movement\n"
p1Winner: .asciz "Player 1 Wins!\n"
p2Winner: .asciz "Player 2 Wins!\n"
playAgainPrompt1: .asciz "Would you like to play another game?\n"
playAgainPrompt2: .asciz "Enter 1 to repeat or 0 to exit\n"
playAgainPrompt3: .asciz "Enter:"
repeatChoice: .word 0

.text

.global main
main:
	PUSH {LR}

begin:
	LDR R4, address_a
	MOV R5, #0
	MOV R8, #'+'
	MOV R9, #'-'
	MOV R11, #8
	MOV R6, #8
	MOV R10, #0

	BL makeBoard
match:
	BL print
	BL prompt
	BL update
	BL print
	ADD R10, R10, #1
	BL checkWin
	CMP R0, #1
	BNE match
	BEQ playAgain

	POP {LR}
	BX LR

/* Beggining of makeBoard subroutine */
makeBoard:
	PUSH {R6,LR}
	BAL loop

loop:
	CMP R5, #64
	BEQ fillW
	ADD R6, R4, R5
	STR R8, [R6]

	MOV R0, R5
	MOV R1, #8
	BL mod
	CMP R0, #7
	BLEQ swap

	BL swap
	ADD R5, R5, #1
	BAL loop

swap:
	PUSH {LR}
	
	MOV R7, R8
	MOV R8, R9
	MOV R9, R7

	POP {LR}
	BX LR

fillW:
	MOV R5, #0
	MOV R6, #0

fillLoopW:
	CMP R5, #16
	BEQ fillB

	ADD R6, R4, R5
	LDRB R8, [R6]

	CMP R8, #43
	BEQ changeW

	ADD R5, R5, #1
	BAL fillLoopW

changeW:
	mov r7, #'o'
	ADD R6, R4, R5
	STRB R7, [R6]
	ADD R5, R5, #1
	BAL fillLoopW

fillB:
	MOV R5, #48
	MOV R6, #0

fillLoopB:
	CMP R5, #64
	BEQ endFill

	ADD R6, R4, R5
	LDRB R8, [R6]

	CMP R8, #43
	BEQ changeB

	ADD R5, R5, #1
	BAL fillLoopB

changeB:
	mov r7, #'*'
	ADD R6, R4, R5
	STRB R7, [R6]
	ADD R5, R5, #1
	BAL fillLoopB

endFill:
	POP {R6,LR}
	BX LR

/* End of makeBoard subroutine */

/* Beginning of mod subroutine */
mod:
	PUSH {LR}

	MOV R3, #0
	BAL check

check:
	CMP R0, R1
	BGE subtract

	POP {LR}
	BX LR

subtract:
	ADD R3, R3, #1
	SUB R0, R0, R1
	BAL check

/* End of mod subroutine */

/* Beginning of div subroutine */
div:
	PUSH {LR}

	MOV R3, #0
	BAL divCheck

divCheck:
	CMP R0, R1
	BGE divSubtract
	MOV R0, R3

	POP {LR}
	BX LR

divSubtract:
	ADD R3, R3, #1
	SUB R0, R0, R1
	BAL divCheck

/* End of div subroutine */

/* Beginning of print subroutine */
print:
	PUSH {LR}

	LDR R0, address_under
	BL printf
	LDR R0, address_header
	BL printf
	LDR R0, address_b1
	MOV R1, R11
	BL printf
	LDR R0, address_endb1
	MOV R1, R6
	BL printf

	PUSH {R6}

	LDR R4, address_a
	MOV R5, #0
	MOV R6, #0
	BAL printLoop

printLoop:
	CMP R5, #64
	BEQ endFill

	MOV R0, R5
	MOV R1, #8
	BL mod
	CMP R0, #0
	BLEQ rowNum

	ADD R6, R4, R5
	ldrb r6, [r6]
	mov r1, r6
	LDR R0, address_format2
	BL printf

	MOV R0, R5
	MOV R1, #8
	BL mod
	CMP R0, #7
	BLEQ endline

	ADD R5, R5, #1
	BAL printLoop

endline:
	PUSH {LR}

	CMP R5, #7
	BLEQ endBox
	LDR R0, address_format3
	LDR R1, address_endl
	LDR R1, [R1]
	BL printf

	LDR R0, address_border
	BL printf

	POP {LR}
	BX LR

endBox:
	PUSH {LR}

	LDR R0, address_b2
	BL printf

	POP {LR}
	BX LR

rowNum:
	PUSH {LR}
	MOV R0, R5
	MOV R1, #8
	BL div
	ADD R0, R0, #1
	MOV R1, R0

	LDR R0, address_formatd
	
	BL printf

	POP {LR}
	BX LR

/* End of print subroutine */

/* Beginning of prompt subroutine */
prompt:
	PUSH {LR}

checks:
	MOV R0, R10
	MOV R1, #2
	BL mod
	MOV R1, R0
	ADD R1, R1, #1
	MOV R5, R1
	LDR R0, address_player
	BL printf

	LDR R0, address_choicePrompt1
	BL printf
	LDR R0, address_format
	LDR R1, address_choice
	BL scanf
	BL getIndex

	CMP R5, #1
	BLEQ validSelect1
	CMP R1, #1
	BEQ checks

	CMP R5, #2
	BLEQ validSelect2
	CMP R1, #1
	BEQ checks

	PUSH {R0}
	LDR R0, address_choicePrompt2
	BL printf
	LDR R0, address_format
	LDR R1, address_choice
	BL scanf
	BL getIndex
	MOV R1, R0
	POP {R0}

	CMP R5, #1
	BLEQ validMove1
	CMP R2, #1
	BEQ checks

	CMP R5, #2
	BLEQ validMove2
	CMP R2, #1
	BEQ checks

	POP {LR}
	BX LR

getIndex:
	PUSH {R5,R6,LR}

	LDR R1, address_choice
	LDRB R2, [R1,#0]
	LDRB R3, [R1,#1]
	
	CMP R2, #96
	SUBGT R2, R2, #97
	SUBLT R2, R2, #65
	SUB R3, R3, #49
	MOV R5, #8
	MUL R6, R3, R5
	ADD R6, R6, R2
	MOV R0, R6

	POP {R5,R6,LR}
	BX LR

validSelect1:
	PUSH {R5,LR}

	ADD R5, R4, R0
	LDRB R2, [R5]
	CMP R2, #'*'
	MOVNE R1, #1
	BLNE invalidSelect

	POP {R5,LR}
	BX LR

validSelect2:
	PUSH {R5,LR}

	ADD R5, R4, R0
	LDRB R2, [R5]
	CMP R2, #'o'
	MOVNE R1, #1
	BLNE invalidSelect

	POP {R5,LR}
	BX LR

invalidSelect:
	PUSH {R1,LR}

	LDR R0, address_invalid1
	BL printf

	POP {R1,LR}
	BX LR

validMove1:
	PUSH {R5,LR}

	SUB R5, R0, R1
	CMP R5, #7
	BEQ stop1
	CMP R5, #9
	BEQ stop1

	CMP R5, #14
	BLEQ jumpCheck

	CMP R5, #18
	BLEQ jumpCheck
	CMP R2, #0
	BEQ stop1

	BL invalidMove
	MOV R2, #1

	POP {R5,LR}
	BX LR

validMove2:
	PUSH {R5,LR}

	SUB R5, R1, R0
	CMP R5, #7
	BEQ stop1
	CMP R5, #9
	BEQ stop1

	CMP R5, #14
	BLEQ jumpCheck

	CMP R5, #18
	BLEQ jumpCheck
	CMP R2, #0
	BEQ stop1

	BL invalidMove2
	MOV R2, #1

	POP {R5,LR}
	BX LR

jumpCheck:
	PUSH {R5,R7,LR}

	LDR R4, address_a
	ADD R5, R0, R1
	PUSH {R0,R1}
	MOV R0, R5
	MOV R1, #2
	BL div

	ADD R5, R4, R0
	LDRB R7, [R5]

	MOV R0, R10
	MOV R1, #2
	BL mod
	MOV R1, R0
	ADD R1, R1, #1

	CMP R1, #1
	BLEQ p1Jump
	CMP R1, #2
	BLEQ p2Jump
	
	POP {R0,R1,R5,R7,LR}
	BX LR

stop1:
	MOV R2, #0
	POP {R5,LR}
	BX LR

invalidMove:
	PUSH {LR}

	LDR R0, address_invalid2
	BL printf

	POP {LR}
	BX LR

invalidMove2:
	PUSH {LR}

	LDR R0, address_invalid3
	BL printf

	POP {LR}
	BX LR

p1Jump:
	PUSH {LR}

	CMP R7, #'o'
	MOVNE R2, #1
	MOVEQ R2, #0
	BLEQ remove1

	POP {LR}
	BX LR

remove1:
	PUSH {R8,LR}
	
	MOV R8, #'+' 
	STRB R8, [R5]
	SUB R6, R6, #1

	POP {R8,LR}
	BX LR

p2Jump:
	PUSH {LR}

	CMP R7, #'*'
	MOVNE R2, #1
	MOVEQ R2, #0
	BLEQ remove2

	POP {LR}
	BX LR

remove2:
	PUSH {R8,LR}
	
	MOV R8, #'+' 
	STRB R8, [R5]
	SUB R11, R11, #1

	POP {R8,LR}
	BX LR

/* End of prompt subroutine */

/* Beginning of update subroutine */
update:
	PUSH {LR}
	
	LDR R4, address_a
	ADD R2, R4, R0
	LDRB R3, [R2]
	MOV R5, R3

	ADD R2, R4, R1
	LDRB R3, [R2]
	STRB R5, [R2]
	ADD R2, R4, R0
	STRB R3, [R2]

	POP {LR}
	BX LR

/* End of update subroutine */

/* Beginning of checkWin subroutine */
checkWin:
	PUSH {LR}

	CMP R6, #0
	BLEQ p1Wins
	MOVEQ R0, #1
	MOVNE R0, #0

	CMP R11, #0
	BLEQ p2Wins
	MOVEQ R0, #1
	MOVNE R0, #0

	POP {LR}
	BX LR

p1Wins:
	PUSH {LR}

	LDR R0, address_p1Winner
	BL printf

	POP {LR}
	BX LR

p2Wins:
	PUSH {LR}

	LDR R0, address_p2Winner
	BL printf

	POP {LR}
	BX LR

playAgain:
	LDR R0, address_playAgainPrompt1
	BL printf
	LDR R0, address_playAgainPrompt2
	BL printf
	LDR R0, address_playAgainPrompt3
	BL printf
	LDR R0, address_inputd
	LDR R1, address_repeatChoice
	BL scanf

	LDR R1, address_repeatChoice
	LDR R1, [R1]
	CMP R1, #1
	BEQ begin
	BNE end

/* End of checkWin subroutine */

end:
	POP {LR}
	BX LR

/* Data addresses */
address_a: .word a
address_headline: .word h
address_under: .word under
address_header: .word header
address_b1: .word b1
address_b2: .word b2
address_endb1: .word endb1
address_border: .word border
address_endl: .word endl
address_format: .word format
address_format1: .word format1
address_format2: .word format2
address_format3: .word format3
address_formatd: .word formatd
address_inputd: .word inputd
address_choicePrompt1: .word choicePrompt1
address_choicePrompt2: .word choicePrompt2
address_choice: .word choice
address_player: .word player
address_invalid1: .word invalid1
address_invalid2: .word invalid2
address_invalid3: .word invalid3
address_p1Winner: .word p1Winner
address_p2Winner: .word p2Winner
address_playAgainPrompt1: .word playAgainPrompt1
address_playAgainPrompt2: .word playAgainPrompt2
address_playAgainPrompt3: .word playAgainPrompt3
address_repeatChoice: .word repeatChoice
