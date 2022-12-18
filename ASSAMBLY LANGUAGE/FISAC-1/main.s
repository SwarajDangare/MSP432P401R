	AREA main, CODE , READONLY
	EXPORT __main
	ENTRY 
__main
	LDR R1, =src
	LDR R2, =src
	LDR R3, =0x20001000
	MOV R4, #'N'
    MOV R5, #'Y'
	
loop 
	LDRB R6,[R2],#1
	MOVS R7, R6
	BNE loop
	SUB R2, #1
loop1
	LDRB R8, [R1], #1
	LDRB R9, [R2], #-1
	CMP R8, R9
	BNE NOT
	CMP R1,R2
	MOVEQ R10, R5
	STR R10, [R3]
	BEQ STOP
	BNE loop1
NOT
	STR R4, [R3]
	B STOP
STOP B STOP
	
	ALIGN

	AREA srcHEY, DATA, READONLY
src DCB "TARUSHCHUTIYA",0
	END
	
	
