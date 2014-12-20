/* TempConvert2.s */

.data
prompt: .asciz "Enter a number in fahrenheit:"
formatd: .asciz "%d"
num: .word 0
result: .asciz "Celcius:%d\n";

.text
	
.global main
main:
	PUSH {LR}

getInput:
	LDR R0, address_prompt
	BL printf

	LDR R0, address_formatd
	LDR R1, address_num
	BL scanf

	LDR R1, address_num
	LDR R1, [R1]
	CMP R1, #32
	BLT getInput

	LDR R1, address_num
	LDR R1, [R1]
	LDR R2, =212
	CMP R1, R2
	BGT getInput

convert:
	LDR R1, address_num
	LDR R1, [R1]
	SUB R1, R1, #32
	LDR R6, =0x8e38f
	MUL R1, R6, R1
	ASR R1, #20

output:
	LDR R0, address_result
	BL printf

end:
	POP {LR}
	BX LR

address_formatd: .word formatd
address_prompt: .word prompt
address_num: .word num
address_result: .word result
