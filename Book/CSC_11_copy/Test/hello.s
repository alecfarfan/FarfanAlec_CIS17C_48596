.data

message1: .asciz "Enter a number to see that term of the fibonacci sequence:"
message2: .asciz "Result: %d\n"
scan_pattern: .asciz "%d"
number_read: .word 0
return: .word 0

.text

.global main
main:
	ldr r1, address_of_return
	str lr, [r1]

	ldr r0, address_of_message1
	bl printf

	ldr r0, address_of_scan_pattern
	ldr r1, address_of_number_read
	bl scanf

	ldr r0, address_of_message2
	ldr r1, address_of_number_read
	ldr r1, [r1]
	bl printf

	ldr r0, address_of_number_read
	ldr r0, [r0]
	ldr lr, address_of_return
	ldr lr, [lr]
	bx lr

address_of_message1: .word message1
address_of_message2: .word message2
address_of_scan_pattern: .word scan_pattern
address_of_number_read: .word number_read
address_of_return: .word return
