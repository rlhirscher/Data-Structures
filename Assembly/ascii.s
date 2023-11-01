/* Ryan Hirscher
 * CSC2410 - Lab 10
 * 3/31/2022
 * This program takes one input and if it is between 30 and 39 it will output the corresponding ascii number value 
 *
 * Compile: as -o ascii.o ascii.s
 *          gcc -o ascii ascii.o
 * Execute: ./ascii ; echo $?
*/

.global main

main:
   mov r1, #50
   mov r2, #10
   cmp r1, r2
   blt bad
   sub r3, r1, r2
   mov r4
   cmp r4, r3
   blt bad
   mov r0, r3
   bx lr

bad:
   mov r0, #50
   bx lr
