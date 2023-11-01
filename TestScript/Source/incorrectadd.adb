-- Ryan Hirscher
-- CSC4510 Dr. Oudshoorn
-- Assignment 1

-- Incorrect Add Procedure
-- Pre: Standard In at least 2 integers
-- Post: Standard out sum of its absolute value
with Text_Io;
use Text_Io;

procedure IncorrectAdd is
   package Int_Io is new Integer_Io(Integer);
   use Int_Io;
   num1, num2 : Integer;

begin
   -- Prompt and Get
   Put_Line("Enter 2 integers to be added together");
   Get(num1);
   Get(num2);

   -- Convert with absolute value
   num1:=abs(num1);
   num2:=abs(num2);

   -- Print and add
   Put(num1, 0);
   Put(" + ");
   Put(num2, 0);
   Put(" = ");
   Put(num1+num2, 0);
   New_Line;
end IncorrectAdd;
