/*
 * Lab 4 - Noah Marchman
 * Collatz Sequence Finder
 * Finds the number less than 100 with the longest Collatz sequence
 */

    .syntax unified
    .cpu cortex-m4
    .thumb

	.global main
	.section .data

longest:    .word 0     // Stores the number with longest sequence
length:     .word 0     // Stores the length of longest sequence


/*
 * Main function
 * Iterates through numbers 1-99 and finds the longest Collatz sequence
 */
	.section .text
main:
    push {r4, r5, r6, lr}

    mov r4, #1          // r4 = current number to test
    mov r5, #0          // r5 = max length found so far
    mov r6, #0          // r6 = number with max length

test_loop:
    cmp r4, #100        // Check if we've tested all numbers < 100
    bge done

    mov r0, r4          // Pass current number to collatz_length
    bl collatz_length   // r0 = length of sequence

    cmp r0, r5          // Compare with current max length
    ble not_longer

    mov r5, r0          // Update max length
    mov r6, r4          // Update number with max length

not_longer:
    add r4, r4, #1      // Increment to next number
    b test_loop

done:
    // Store results in memory
    ldr r0, =longest
    str r6, [r0]        // Store the number with longest sequence

    ldr r0, =length
    str r5, [r0]        // Store the length

    pop {r4, r5, r6, pc}

/*
 * Recursive function: collatz_length
 * Calculates the length of the Collatz sequence for a given number
 * Input: r0 = number
 * Output: r0 = sequence length
 */
collatz_length:
    push {r4, lr}

    mov r4, r0          // Save the input number

    // Base case: if n == 1, return 1
    cmp r0, #1
    bne not_base_case

    mov r0, #1          // Sequence length is 1 when we reach 1
    pop {r4, pc}

not_base_case:
    // Check if number is even or odd
    bl is_even          // r0 = 1 if even, 0 if odd

    cmp r0, #1
    beq even_case

odd_case:
    // If odd: n = 3n + 1
    mov r0, r4
    mov r1, #3
    mul r0, r1, r0      // r0 = 3 * n
    add r0, r0, #1      // r0 = 3n + 1
    bl collatz_length   // Recursive call
    add r0, r0, #1      // Add 1 to the sequence length
    pop {r4, pc}

even_case:
    // If even: n = n / 2
    mov r0, r4
    lsr r0, r0, #1      // r0 = n / 2 (logical shift right)
    bl collatz_length   // Recursive call
    add r0, r0, #1      // Add 1 to the sequence length
    pop {r4, pc}

/*
 * Subroutine: is_even
 * Checks if a number is even
 * Input: r0 = number to check
 * Output: r0 = 1 if even, 0 if odd
 */
is_even:
    push {lr}

    and r1, r0, #1      // r1 = r0 & 1 (check least significant bit)
    cmp r1, #0
    beq return_even

    mov r0, #0          // Odd
    pop {pc}

return_even:
    mov r0, #1          // Even
    pop {pc}
