/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call By Value Result Java
 *
 * Java is sctrictly built to support pass by value. Addresses are not able to be retrieved for variables.
 *
 * Java does not support Call by Value-Result directly. However, it can be implmeneted to accomplish the same feature through defining your own class objects. These objects are referenced through pointers under the hood, so changes made to the formal parameters will be reflected back to the actuals. This utilizes aliasing to accomplish call by value result.
 *
 * Actual value changes are reflected in main.
*/

//Callee and defining object class CallByVal
class CallByVal {
   int X, Y;

   //Method for assignment
   CallByVal(int x, int y)
   {
      X=x;
      Y=y;
   }

   //Method to add
   static void addFive(CallByVal obj)
   {
         System.out.println("Formals: X=" + obj.X + " Y=" + obj.Y);

         //Copying/adding back at the time of return
         obj.X+=5;
         obj.Y+=5;
         return;
   }
}

//Caller
class CallByValueResult {
   public static void main(String[] args)
   {
      //Declaring object type CallByVal named obj
      //New instance and storing 5 as X and 12 as Y
      CallByVal obj = new CallByVal(5, 12);

      System.out.println("Call By Value Result (class object) to addFive function.");
      System.out.println("Actuals Pre-add: X=" + obj.X + " Y=" + obj.Y);

      //Calling
      obj.addFive(obj);

      System.out.println("Actuals Post-add: X=" + obj.X + " Y=" + obj.Y);
   }
}
