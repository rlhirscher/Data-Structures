/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Pass By Reference Java
 *
 * Java is sctrictly built to support pass by value. Addresses are not able to be retrieved for variables.
 *
 * Java does not support Pass by Reference directly. However, it can be implmeneted to accomplish the same feature through defining your own class objects. These objects are referenced through pointers under the hood, so changes made to the formal parameters will be reflected back to the actuals. This utilizes aliasing to accomplish call by reference.
 *
 * Actual value changes are reflected in main.
*/

//Callee and defining object class CallByRef
class CallByRef {
   int X, Y;

   //Method for assignment
   CallByRef(int x, int y)
   {
      X=x;
      Y=y;
   }

   //Method to add
   static void addFive(CallByRef obj)
   {
         obj.X+=5;
         obj.Y+=5;
         System.out.println("Formals: X=" + obj.X + " Y=" + obj.Y);
         return;
   }
}

//Caller
class PassByReference {
   public static void main(String[] args)
   {
      //Declaring object type CallByRef named objectActual
      //New instance and storing 5 as X and 12 as Y
      CallByRef obj = new CallByRef(5, 12);

      System.out.println("Pass by Reference (class object) to addFive function.");
      System.out.println("Actuals Pre-add: X=" + obj.X + " Y=" + obj.Y);

      //Calling
      obj.addFive(obj);

      System.out.println("Actuals Post-add: X=" + obj.X + " Y=" + obj.Y);
   }
}
