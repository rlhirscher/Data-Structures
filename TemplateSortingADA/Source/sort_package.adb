--  This is the implementation of the generic sort routine. 
--  The Sort has been packaged for use in the test_sort
package body SORT_PACKAGE is
procedure SORT(ARR: in out ARRAY_TYPE) is
    -- generic sort using insertion sort

    J: INDEX;
    TEMP: ELEMENT;
    STOP: BOOLEAN;

    function NEXT(X: in INDEX) return INDEX is
      -- find the next index in the array
     begin -- NEXT
       if X=INDEX'LAST
       then
         return INDEX'FIRST;
       else
         return INDEX'SUCC(X);
       end if;
     end NEXT;

    function PREV(X: in INDEX) return INDEX is
      -- find the previous index to the array
      begin -- PREV
        if X = INDEX'FIRST
        then
          return INDEX'LAST;
        else
          return INDEX'PRED(X);
        end if;
      end PREV;


    begin -- SORT
      for I in ARR'FIRST..PREV(ARR'LAST)
      loop
        -- arr(arr_type'first) to arr(i) are now sorted.
        -- Extend this to arr(i+1)
        if ARR(NEXT(I)) < ARR(I)
        then
          -- move ARR(i+1) back into its place in the array.  First save its
          -- value in temp and then move earlier elements up one place until
          -- the right place is found.
          TEMP := ARR(NEXT(I));
          J := I;
          STOP := FALSE;
          while (not STOP) and then (TEMP < ARR(J))
          loop
            ARR(NEXT(J)) := ARR(J);
            if J = INDEX'FIRST
            then
              STOP := TRUE;
            else
              J := PREV(J);
            end if;
          end loop;
          if STOP
          then
            ARR(J) := TEMP;
          else
            ARR(NEXT(J)) := TEMP;
          end if;
        end if;
      end loop;
    end SORT;
end SORT_PACKAGE;
