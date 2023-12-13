/*
 *   Ryan Hirscher
 *   ID_table_entry.h
 *   12/8/2023
 *   Final Submission
*/

#ifndef ID_TABLE_ENTRY_H_
#define ID_TABLE_ENTRY_H_

#include <iostream>
#include <string>

#include "id_table.h"
#include "id_table_entry.h"
#include "token.h"
#include "lille_type.h"
#include "lille_kind.h"

using namespace std;

class id_table_entry {
   private:
      bool dbg_tbl = {false};
      token* id_entry;
      int l_entry;
      int offset_entry;
      lille_kind kind_entry;
      lille_type type_entry;
      bool trace_entry;
      //Ordered and Arith
      int i_value_entry;
      float r_value_entry;
      string s_value_entry;
      bool b_value_entry;
      id_table_entry* p_list_entry;
      int p_count;
      lille_type r_typ_entry;

   public:
      bool trace();
      id_table_entry();
      id_table_entry(token* id, lille_type tip=lille_type::type_unknown,
                     lille_kind knd = lille_kind::unknown,
                     int level = 0, int offset = 0,
                     lille_type return_tip = lille_type::type_unknown);
      //Get functions
      int get_offset();
      int get_level();
      lille_kind get_kind();
      lille_type get_type();
      token* get_token_value();
      string get_name();
      int get_integer_value();
      float get_real_value();
      bool get_bool_value();
      string get_string_value();

      lille_type return_tip(); //Return type
      void const_val(int intval=0, float rval=0, string sval="", bool bval=false); //Constant assignment
      void const_return(lille_type ret_typ=lille_type::type_unknown); //Constant return

      //Parameter handling
      void add_p(id_table_entry* p_entry);
      id_table_entry* parameters(int n);
      int get_p_count();

      string print_string();
};

#endif

