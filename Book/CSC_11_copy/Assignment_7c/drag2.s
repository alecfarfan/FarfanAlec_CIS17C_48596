/* drag2.s */

.data
half: .float 0.5
threetwo: .float 32
rho: .float 0.00237
velocity: .word 0
radius: .word 00237
pi: .float 3.1415926
conv: .float 0.006944444
cd: .float 0.4
prompt1: .asciz "Enter the velocity:"
prompt2: .asciz "Enter the radius:"
formatf: .asciz "%f"
result1: .asciz "Floating Dynamic Pressure = %f (lbs)\n";
result2: .asciz "Cross Section Area x32 = %f (ft^2)\n"
result3: .asciz "Floating Drag x 32 = %f (lbs)\n"

.text
	
.global main
main:
	PUSH {R4, LR}
	LDR R0, address_prompt1
	BL printf

	LDR R0, address_formatf
	LDR R1, address_velocity
	BL scanf

	LDR R0, address_prompt2
	BL printf

	LDR R0, address_formatf
	LDR R1, address_radius
	BL scanf

	LDR R1, address_velocity
	VLDR S5, [R1]
	LDR R1, address_half
	VLDR S6, [R1]
	LDR R1, address_rho
	VLDR S4, [R1]

	VMUL.F32 S5, S4, S5
	VMUL.F32 S4, S5, S6
	VMUL.F32 S4, S4, S5

	LDR R1, address_pi
	VLDR S7, [R1]
	LDR R1, address_radius
	VLDR S8, [R1]
	LDR R1, address_conv
	VLDR S9, [R1]

	VMUL.F32 S6, S7, S8
	VMUL.F32 S6, S6, S8
	VMUL.F32 S6, S6, S9

	LDR R1, address_cd
	VLDR S3, [R1]
	VMUL.F32 S8, S4, S6
	VMUL.F32 S8, S8, S3

	LDR R1, address_threetwo
	VLDR S5, [R1]
	VMUL.F32 S8, S8, S5
	VMUL.F32 S6, S6, S5
	VCVT.F64.F32 D15, S8
	VCVT.F64.F32 D14, S6
	VCVT.F64.F32 D13, S4

print:
	LDR R0, address_result1
	VMOV R2, R3, D13
	BL printf

	LDR R0, address_result2
	VMOV R2, R3, D14
	BL printf

	LDR R0, address_result3
	VMOV R2, R3, D15
	BL printf

end:
	POP {R4,LR}
	BX LR

address_half: .word half
address_threetwo: .word threetwo
address_rho: .word rho
address_velocity: .word velocity
address_radius: .word radius
address_pi: .word pi
address_conv: .word conv
address_cd: .word cd
address_prompt1: .word prompt1
address_prompt2: .word prompt2
address_formatf: .word formatf
address_result1: .word result1
address_result2: .word result2
address_result3: .word result3
