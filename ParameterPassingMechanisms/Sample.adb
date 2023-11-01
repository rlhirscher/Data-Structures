with Text_Io;
procedure Sample_Ada is
 package Int_Io is new Text_Io.Integer_Io (Integer);
 A_I, A_J, A_K: Integer;
 procedure Proc (F_I: in Integer; F_J: out Integer; F_K: in out Integer) is
 -- f_i, f_j, and f_k are the FORMAL parameters
 begin -- Proc
 Text_Io.Put_Line("Inside Proc...");
 Int_Io.Put(A_I);
 Int_Io.Put(A_J);
 Int_Io.Put(A_K);
 Text_Io.New_Line;
 Int_Io.Put(F_I);
 -- Int_Io.Put(F_J); -- illegal, f_j must be assigned a value first
 Int_Io.Put(F_K);
 Text_Io.New_Line;
 -- f_i := 10; -- illegal statement
 F_J := 11;
 F_K := 12;
 Text_Io.Put_Line("Just before Proc returns...");
 Int_Io.Put(A_I);
 Int_Io.Put(A_J);
 Int_Io.Put(A_K);
 Text_Io.New_Line;
 Int_Io.Put(F_I);
 Int_Io.Put(F_J);
 Int_Io.Put(F_K);
 Text_Io.New_Line;
 Text_Io.Put_Line("Proc ends.");
 end Proc;
begin -- sample_ada
 A_I := 1;
 A_J := 2;
 A_K := 3;
 Text_IO.Put_Line("Before the Call to Proc...");
 Int_Io.Put(A_I);
 Int_Io.Put(A_J);
 Int_Io.Put(A_K);
 Text_Io.New_Line;
 Proc(A_I, A_J, A_K);
 -- a_i, a_j, a_K are the ACTUAL parameters
 Text_Io.Put_Line("after the call to Proc...");
 Int_Io.Put(A_I);
 Int_Io.Put(A_J);
 Int_Io.Put(A_K);
 Text_Io.New_Line;
end Sample_Ada;
