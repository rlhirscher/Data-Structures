/* Ryan Hirscher
 * Dr. Oudshoorn
 * CSC4510
 * Assignment 2 Call By Result Java
 *
 * Java is sctrictly built to support pass by value. Addresses are not able to be retrieved for variables.
 *
 * Java does not support Call by Result. However, it can be implmeneted to accomplish similar behavior through defining your own class objects. These objects are referenced through pointers under the hood, so changes made to the formal parameters will be reflected back to the actuals even if you were to change the name of the formal parameters. So passing a dummy variable and assigning it new value at the return would reflect how Call By Result should function.
 *
 * Actual value changes are reflected in main.
*/

//Callee and defining object class CallByRef
class CallByR {
   int X, Y;

   //Method for assignment
   CallByR(int x, int y)
   {
      X=x;
      Y=y;
   }

   //Method to add 
   static void addFive(CallByR obj, CallByR res)
   {
         obj.X+=5;
         obj.Y+=5;
         System.out.println("Formals: X=" + obj.X + " Y=" + obj.Y);
         System.out.println("Formals Result: X=" + res.X + " Y=" + res.Y);

         res.X=obj.X;
         res.Y=obj.Y;
         return;
   }
}

//Caller
class CallByResult {
   public static void main(String[] args)
   {
      //Declaring object type CallByR named objectActual and objectResult
      //New instance and storing 5 as X and 12 as Y and dummy object with 0s
      CallByR objectActual = new CallByR(5, 12);
      CallByR objectResult = new CallByR(0,0);

      System.out.println("Call By Result (class object) to addFive function.");
      System.out.println("Actuals Pre-add: X=" + objectActual.X + " Y=" + objectActual.Y);
      System.out.println("Actuals Result: X=" + objectResult.X + " Y=" + objectResult.Y);

      //Calling
      objectActual.addFive(objectActual, objectResult);

      System.out.println("Actuals Post-add: X=" + objectActual.X + " Y=" + objectActual.Y);
      System.out.println("Post-add Result: X=" + objectResult.X + " Y=" + objectResult.Y);
   }
}
