procedure Scope_Ada is
 I, J, K: Integer;
 procedure A is
 M, N, O: Integer;
 begin -- A
 -- i, j, k, m, n, o and A, scope_ada visible here
 -- m., n, o are local to the procedure A and only visible within it.
 null;
 end A;
 procedure B is
 I, M, P: Integer;
 begin -- B
 -- i, j, k, m, p and a, b, scope_ada visible here.
 -- The i that is visible is the I declared inside procedure B.
 -- It masks the i declared in Scope_ada which can only be accessed
 -- as scope_ada.I inside procedure B.
 null;
 end B;
begin --scope_ada
 -- i, j, k and a, b, scope_ada are visible here
 null;
end Scope_Ada;
