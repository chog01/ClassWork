
.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

.section .data
.align
// Sue = 0x12345678abcdefed98765432----------------------------------------------------
Sue:
    .word 0x98765432 //MSW
    .word 0xabcdefed
    .word 0x12345678 //LSW

// Joe = 0xbbbbeeeeaaaa12378987dcba----------------------------------------------------
Joe:
    .word 0x8987dcba
    .word 0xaaaa1237
    .word 0xbbbbeeee

// Ann = 0x1f2bcab01ef67edcba345678---------------------------------------------------
Ann:
    .word 0xba345678
    .word 0x1ef67edc
    .word 0x1f2bcab0

// Bob is reserved space for the result-----------------------------------------------
Bob:
    .space 12





//Main code - It took me forever to figure out the data needed to go outside of here :)
.section .text
.align
.global main

main:
//Loading Data-----------------------------------------------------------------------
	ldr   r0, =Sue
	ldr   r1, =Joe
	ldr   r2, =Ann
	ldr   r3, =Bob

//Part 1: Calculate Temp = Sue + Joe-------------------------------------------------

    // Load and add LSW
    ldr   r4, [r0]
    ldr   r5, [r1]
    adds  r8, r4, r5

    // Load and add middle
    ldr   r4, [r0, #4]
    ldr   r5, [r1, #4]
    adc   r9, r4, r5

    // Load and add MSW
    ldr   r4, [r0, #8]
    ldr   r5, [r1, #8]
    adc   r10, r4, r5

//Part 2: Calculate Bob = Temp - Ann-------------------------------------------------

    // Load and subtract LSW of Ann / store in bob[0]
    ldr   r6, [r2]
    subs  r4, r8, r6
    str   r4, [r3]

    // Load and subtract middle word of Ann / store in bob[1]
    ldr   r6, [r2, #4]
    sbc   r5, r9, r6
    str   r5, [r3, #4]

    // Load and subtract MSW of Ann / store in bob[3]
    ldr   r6, [r2, #8]
    sbc   r7, r10, r6
    str   r7, [r3, #8]

forever:
	b     forever
