/* -- evenSum.s */
/* Ryan Hirscher
 * CSC 2410 Lab11: Summation of Even numbers between 0 and 22. ANS: 132
 * Compile: as -o evenSum.o evenSum.s
 *          gcc -o evenSum evenSum.o
 * Execute: ./evenSum; echo $?
 */

.global main

main:
   mov r1, #0 //Start
   mov r0, #0 //Total
   mov r4, #22 //End
   mov r2, #2 //Adder
   Loop:
      while_condition:
         add r1, r1, r2
         add r0, r0, r1 
         cmp r1, r4
         bLT while_condition
         bEQ end_of_loop
   
   end_of_loop:
      bx lr
