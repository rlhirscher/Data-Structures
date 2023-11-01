/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call By Name Java
 *
 * Java is sctrictly built to support pass by value. Addresses are not able to be retrieved for variables.
 *
 * Java does not support Call by Name directly. However, it can be implmeneted to accomplish the same feature through defining your own class objects. These objects are referenced through pointers under the hood, so changes made to the formal parameters will be reflected back to the actuals even if you were to change the name of the formal parameters. This utilizes aliasing to accomplish call by call by name.
 *
 * Actual value changes are reflected in main.
*/

//Callee and defining object class CallByN
class CallByN {
   int X, Y;

   //Method for assignment
   CallByN(int x, int y)
   {
      X=x;
      Y=y;
   }

   //Method to add 
   static void addFive(CallByN objNew)
   {
         objNew.X+=5;
         objNew.Y+=5;
         System.out.println("Formals: X=" + objNew.X + " Y=" + objNew.Y);
         return;
   }
}

//Caller
class CallByName {
   public static void main(String[] args)
   {
      //Declaring object type CallByN named objectActual
      //New instance and storing 5 as X and 12 as Y
      CallByN objectActual = new CallByN(5, 12);

      System.out.println("Call By Name (class object) to addFive function.");
      System.out.println("Actuals Pre-add: X=" + objectActual.X + " Y=" + objectActual.Y);

      //Calling
      objectActual.addFive(objectActual);

      System.out.println("Actuals Post-add: X=" + objectActual.X + " Y=" + objectActual.Y);
   }
}
