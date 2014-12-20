/* Test.s */
.data
prompt: .asciz "Enter a number to generate that term in the fibonacci sequence"
format: .asciz "%d"
input: .word 0

.balign 4
return: .word 0

.text
	.global main
main:

	ldr r1, address_return
	str lr,[r1]

	ldr r0, address_prompt
	bl printf

	@ldr r0, address_format
	@ldr r1, address_input
	@bl scanf

	@ldr r4, address_input
        @ldr r4, [r4]

	MOV R3, #0
	MOV R4, #1
	MOV R5, #1
	MOV R6, #13	

	BAL _check
	
_fibonacci:
	ADC R7, R3, R4
	MOV R0, R7
	MOV R3, R4
	MOV R4, R7
	ADD R5, #1

_check:
	CMP R5, R6
	BNE _fibonacci
	@mov r0, r4
	@bl printf
_end:
	ldr r1, address_return
	ldr lr, [lr]
	bx lr

address_prompt: .word prompt
address_return: .word return
address_input: .word input
