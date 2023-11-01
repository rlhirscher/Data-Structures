/* -- myMod */
/* Ryan Hirscher
 * CSC2410 Modulus Calculator
 * Compile: as -o myMod.o myMod.s
 *          gcc -o myMod myMod.o
 * Execute: ./myMod;echo $?
 */ 
.global main

main:
   mov r1 #2 //This is y
   mov r2 #19 //This is x
   udiv r3, r2, r1 //r3 = how many times y can go into x
   mul r4, r1, r3 //r4 = y * r3
   sub r0, r2, r4 //Subtract new value from x and get final to store in r0
   bx lr //Return
