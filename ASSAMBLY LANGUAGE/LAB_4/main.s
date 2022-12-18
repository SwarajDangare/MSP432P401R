	AREA SATURATION, CODE , READONLY
	EXPORT __main
	ENTRY 
__main
	MOV R0, #30
	MOV R1, #0XA5

here RSB R1, R1, #0XFF
	SUBS R0, #1
	BNE here
	END
		