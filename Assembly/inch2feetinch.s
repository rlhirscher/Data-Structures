/* -- Ryan Hirscher
 * CSC2410
 * Description: This assembly program converts a given amount of inches to feet and remaining inches
 * The purpose of this program is to utilize gdb debugging tool to trace the steps of the program using
 * start
 * disas
 * stepi
 * continue
 *
 * Compile: as -o inch2feetinch.o inch2feetinch.s
 *          gcc -o inch2feetinch inch2feetinch.o
 * Execute: gdb --args ./inch2feetinch
 */

.global main

main:
   mov r1, #15
   mov r2, #12
   udiv r11, r1, r2
   mul r4, r11, r2
   sub r12, r1, r4
