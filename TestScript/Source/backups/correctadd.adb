-- Ryan Hirscher
-- CSC4510 Dr. Oudshoorn
-- Assignment 1

-- Correct Add in Ada
-- Pre: Standard in at least 2 integers
-- Post: Standard out the sum of the first two integers
with Text_Io;
use Text_Io;

procedure CorrectAdd is
   package Int_Io is new Integer_Io(Integer);
   use Int_Io;
   num1, num2 : Integer;

begin
   -- Prompt and Get
   Put_Line("Enter 2 integers to be added together");
   Get(num1);
   Get(num2);

   -- Print and add
   Put(num1, 0);
   Put(" + ");
   Put(num2, 0);
   Put(" = ");
   Put(num1+num2, 0);
   New_Line;
end CorrectAdd;
