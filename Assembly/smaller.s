/* Ryan Hirscher
 * CSC2410 - Lab 10
 * 3/31/2022
 * This program chooses the smaller of 2 input variables stored in r1 and r2.
 *
 * Compile: as -o smaller.o smaller.s
 *          gcc -o smaller smaller.o
 * Execute: ./smaller ; echo $?
*/

.global main

main:
   mov r1, #50
   mov r2, #10
   cmp r1, r2
   ble firstCondition
   bge secondCondition

firstCondition:
   mov r0, r1
   bx lr
secondCondition:
   mov r0, r2
   bx lr
