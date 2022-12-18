		AREA main, CODE, READONLY
		EXPORT __main
		ENTRY
__main 
		LDR R5, =0X20000000
		MOV R1, #0
		MOV R2, #1
		STRB R1 ,[R5],#1
		STRB R2 ,[R5],#1
		MOV R0, #8
loop	ADD R3, R2, R1
		MOV R1, R2
		MOV R2, R3
		STRB R3, [R5],#1
		SUBS R0,#1
		BNE loop
		END
	