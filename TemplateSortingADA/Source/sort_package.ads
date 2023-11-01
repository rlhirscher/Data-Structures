--This file is a specification file that declares the sort within the sorting package to be generic
--Aditionally, the < is overloaded to accept different comparisons
package SORT_PACKAGE is
generic
   type ELEMENT is private;
   type Index is (<>);
   with function "<" (Left, Right : ELEMENT) return Boolean is <>;
   type ARRAY_TYPE is array (Index range <>) of ELEMENT;
   procedure SORT (ARR: in out ARRAY_TYPE);
end SORT_PACKAGE;
