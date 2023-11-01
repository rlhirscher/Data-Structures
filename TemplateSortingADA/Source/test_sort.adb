-- Code provided. Edited to use a sort procedure from sort_package.adb
with TEXT_IO;
with SORT_PACKAGE;
use SORT_PACKAGE;
use TEXT_IO;

procedure TEST_SORT is
  -- test the generic sorting procedure

  type COLOR is (RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET);
  type MY_RANGE is new NATURAL range 11..20;
  type ARRAY_TYPE is array (MY_RANGE range <>) of COLOR;
  subtype MY_ARRAY_TYPE is ARRAY_TYPE(11..20);
  -- Ada does not require array ndices to begin at 0 as C and C++ does.

  MY_ARR: MY_ARRAY_TYPE := (RED, GREEN, INDIGO,  RED, YELLOW,
                            RED, ORANGE, BLUE, YELLOW, GREEN);
  -- initializes an array of 10 colors.

  -- "<" for enumerated types already exists.
  -- Passing the arguments clearly stating formals and actuals
  procedure SORT_MY_ARRAY is new SORT_PACKAGE.SORT(ELEMENT => COLOR, Index => MY_RANGE, ARRAY_TYPE => ARRAY_TYPE, "<" => "<");
  package COLOR_IO is new ENUMERATION_IO(COLOR);
  use COLOR_IO;
  -- Color is an enumerated tyope and so we need to instantiate a IO package for it.
  
  type MY_COLOR is new COLOR range RED..VIOLET;
  
  type ANOTHER_ARRAY_TYPE is array (MY_COLOR range <>) of Float;
  subtype ANOTHER_ARRAY is ANOTHER_ARRAY_TYPE(RED..VIOLET);
  -- this is an array indexed by colors and holds floating point values
  
  ANOTHER_ARR: ANOTHER_ARRAY := (12.0, -9.4, 26.02, -18.63, 0.0, 123.456, 26.2);
  -- Passing the arguments clearly stating formals and actuals
  procedure SORT_ANOTHER_ARR is new SORT_PACKAGE.SORT(ELEMENT => Float, Index => MY_COLOR, ARRAY_TYPE => ANOTHER_ARRAY_TYPE, "<" => ">"); -- Sort in decending order
					   
  package FLT_IO is new FLOAT_IO(FLOAT);
  use FLT_IO;
  
  package MY_COLOR_IO is new ENUMERATION_IO(MY_COLOR);
  use MY_COLOR_IO;
  
  begin -- TEST_SORT
    PUT_LINE("The first unsorted array is ...");
    for I in MY_ARRAY_TYPE'RANGE
    loop
      PUT(MY_ARR(I));
      NEW_LINE;
    end loop;
    NEW_LINE(2);
    SORT_MY_ARRAY(MY_ARR);
    PUT_LINE("The first sorted array is ...");
    for J in MY_ARRAY_TYPE'RANGE
    loop
      PUT(MY_ARR(J));
      NEW_LINE;
    end loop;
        
    -- and for the second array;
    NEW_LINE(3);  -- leave a space
    PUT_LINE("The second unsorted array is ...");
    for C in ANOTHER_ARRAY'RANGE
    loop
       PUT(ANOTHER_ARR(C), 1, 3, 0);
       NEW_LINE;
    end loop;
    NEW_LINE(2);
    SORT_ANOTHER_ARR(ANOTHER_ARR);
    PUT_LINE("The second sorted array is (decending)...");
    for C in  ANOTHER_ARRAY'Range
    loop
       PUT(ANOTHER_ARR(C), 1, 3, 0);
       NEW_LINE;
    end loop;
    
  end TEST_SORT;
