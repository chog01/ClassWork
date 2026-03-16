.syntax unified
.cpu cortex-m4
.thumb


//Data Section
.section .data
MaxValue:				//The Upper limit
	.word 175

const_10:				//A constant used for division
	.word 10

Armstrong_Results:		//Reserves 100 bytes to store found numbers
	.space 100



//Main Code Section
.section .text
.global main

main:

	//Loading the max value from memory into r2
    LDR R2, =MaxValue
    LDR R2, [R2]

    //Initialize loop counter and result pointer
    MOV R1, #1
    LDR R3, =Armstrong_Results


	Main_Loop:

		//Compares current number to max value and ends the program if larger
	    CMP R1, R2
	    BGT End_Program

	    //calls the Check armstrong branch
	    MOV R0, R1
	    PUSH {R1, R2, R3, LR}
	    BL Check_Armstrong
	    POP {R1, R2, R3, LR}

	    //Store the result returned from the branch(1 if armstrong, 0 if not)
	    CMP R0, #1
	    BNE Next_Number

	    //Storing the number if it is an armstrong number
	    STR R1, [R3]
	    ADD R3, R3, #4

	//Increments to the next number then returns to the start
	Next_Number:
	    ADD R1, R1, #1
	    B Main_Loop

	//Ends the program if r1 > 175
	End_Program:
	    B End_Program


	//The branches below this are responsable for doing all the math required and compairing the produced number
	//to the current number we are on to tell us if it is an armstrong number or not (1 or 0)
	Check_Armstrong:

	    PUSH {R4-R9, LR}

	    MOV R9, R0
	    MOV R4, R0
	    MOV R6, #0
	    LDR R7, =const_10

	    CMP R4, #100
	    BGE Three_Digits_Case
	    CMP R4, #10
	    BGE Two_Digits_Case
	    MOV R5, #1
	    B Sum_Calculation_Loop

	Three_Digits_Case:
	    MOV R5, #3
	    B Sum_Calculation_Loop
	Two_Digits_Case:
	    MOV R5, #2
	    B Sum_Calculation_Loop

	Sum_Calculation_Loop:

	    CMP R4, #0
	    BEQ End_Calculation

	    UDIV R8, R4, R7
	    MLS R1, R8, R7, R4

	    MOV R0, R1
	    MOV R1, R5
	    BL Power_Func

	    ADD R6, R6, R0
	    MOV R4, R8
	    B Sum_Calculation_Loop

	End_Calculation:
	    CMP R6, R9
	    IT EQ
	    MOVEQ R0, #1
	    IT NE
	    MOVNE R0, #0
	    POP {R4-R9, LR}
	    BX LR

	Power_Func:
	    CMP R1, #0
	    ITT EQ
	    MOVEQ R0, #1
	    BXEQ LR
	    MOV R2, R0
	    SUB R1, R1, #1

	Power_Loop:
	    CMP R1, #0
	    BEQ Power_End
	    MUL R2, R2, R0
	    SUB R1, R1, #1
	    B Power_Loop

	Power_End:
	    MOV R0, R2
	    BX LR
