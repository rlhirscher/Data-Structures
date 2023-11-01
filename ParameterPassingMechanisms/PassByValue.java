/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Pass By Value Java
 *
 * Java is sctrictly built to support pass by value. Addresses are not able to be retrieved for variables.
 *
 * Actual value changes are not reflected in main. The value changes of the formal variables remained in the scope of the function.
*/
import java.io.*;
class PassByValue {
   public static void main(String[] args)
   {
      int x=10;
      int y=20;
      System.out.println("Pass by value to addFive function.");
      System.out.println("Actuals Pre-add: " + x + " " + y);
      addFive(x,y);
      System.out.println("Actuals Post-add: " + x + " " + y);
   }
   static void addFive(int x, int y)
   {
         x+=5;
         y+=5;
         System.out.println("Formals: " + x + " " + y);
         return;
   }
}
