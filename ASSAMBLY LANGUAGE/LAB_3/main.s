	AREA main, CODE, READONLY
	EXPORT __main
	ENTRY
__main

	MOV R1, #0x2
	MOV R2, #0x3
	MUL R3, R1, r2
	