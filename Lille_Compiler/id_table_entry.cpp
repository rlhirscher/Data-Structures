/*
 * Ryan Hirscher
 * id_table_entry.cpp
 * 12/1/2023 Semantic Analysis Phase
 *
*/

#include <iostream>
#include "id_table.h"
#include "id_table_entry.h"

//constructor
id_table_entry::id_table_entry()
{
   dbg_tbl = true;
   id_entry = NULL;
   l_entry = 0;
   offset_entry =0;
   kind_entry = lille_kind::unknown;
   type_entry = lille_type::type_unknown;
   trace_entry = false;
   i_value_entry = 0;
   r_value_entry = 0;
   s_value_entry = "";
   b_value_entry = false;
   p_list_entry = NULL;
   p_count = 0;
   r_typ_entry = lille_type::type_unknown;
}

//Build with parameters
id_table_entry::id_table_entry(token* id, lille_type tip, lille_kind knd, int level, int offset, lille_type return_tip)
{
   id_entry = id;
   type_entry = tip;
   kind_entry=knd;
   l_entry = level;
   offset_entry = offset;
   r_typ_entry = return_tip;

   p_list_entry = NULL;
   p_count = 0;
   i_value_entry = 0;
   r_value_entry = 0;
   s_value_entry = "";
   b_value_entry = false;
}

//Get functions
int id_table_entry::get_offset()
{
   return offset_entry;
}
lille_type id_table_entry::return_tip()
{
   return r_typ_entry;
}
int id_table_entry::get_level()
{
   return l_entry;
}
lille_type id_table_entry::get_type()
{
   return type_entry;
}
lille_kind id_table_entry::get_kind()
{
   return kind_entry;
}
token* id_table_entry::get_token_value()
{
   return id_entry;
}
string id_table_entry::get_name()
{
   if (id_entry->get_sym() == symbol::identifier)
      return id_entry->get_identifier_value();
   else if (id_entry->get_sym() == symbol::program_sym)
      return id_entry->get_prog_value();
   else if (id_entry->get_sym() == symbol::procedure_sym)
      return id_entry->get_proc_value();
   else if (id_entry->get_sym() == symbol::function_sym)
      return id_entry->get_func_value();
   else
      return "";
}
int id_table_entry::get_integer_value()
{
   return i_value_entry;
}
float id_table_entry::get_real_value()
{
   return r_value_entry;
}
string id_table_entry::get_string_value()
{
   return s_value_entry;
}
bool id_table_entry::get_bool_value()
{
   return b_value_entry;
}

//Set constant values
void id_table_entry::const_val(int intval, float rval, string sval, bool bval)
{
   i_value_entry = intval;
   r_value_entry = rval;
   s_value_entry = sval;
   b_value_entry = bval;
}
void id_table_entry::const_return(lille_type ret_typ)
{
   this->r_typ_entry = ret_typ;
}

//Parameter handling
void id_table_entry::add_p(id_table_entry* p_entry)
{
   id_table_entry* ptr = this;
   while (ptr->p_list_entry != NULL)
      ptr = ptr->p_list_entry;
   ptr->p_list_entry = p_entry;
   this->p_count++;
   if (dbg_tbl)
      cout <<  "PARAM: " << p_entry->get_name() << " to " << this->get_name() << endl;
}

int id_table_entry::get_p_count()
{
   return p_count;
}

id_table_entry* id_table_entry::parameters(int n)
{
   id_table_entry* ptr = this;
   for (int i=0; i<n+1; i++)
   {
      if (ptr->p_list_entry != NULL)
         ptr = ptr->p_list_entry;
   }
   if (ptr == this)
      return NULL;
   else
      return ptr;
}
bool id_table_entry::trace()
{
   return trace_entry;
}
string id_table_entry::print_string()
{
   return this->get_name() + ":\n" + "Lille Type: " + this->get_type().to_string() + "\nKind: " + this->get_kind().to_string() + "\nScope: " + to_string(this->get_level()) + "\nReturn Type: " + this->r_typ_entry.to_string(); 
}

