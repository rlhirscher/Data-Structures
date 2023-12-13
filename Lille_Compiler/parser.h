/*
 *   Ryan Hirscher
 *   CSC4510 Program Language Design/Translation
 *   Parser header
 *   12/1/2023
 *
 *
*/
#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <list>
#include <algorithm>

#include "scanner.h"
#include "token.h"
#include "error_handler.h"
#include "id_table.h"
#include "symbol.h"

using namespace std;

class parser {
   public:

      //Constructor
      parser(scanner* scn, error_handler* err, id_table* t);

      //Destructor
      ~parser();

      //Start
      void program();

   private:

      //Traces entry and exit
      bool debgg = {false};
   
      bool checking = {false};

      scanner* scan;
      id_table* table;
      error_handler* error;     
  
      //Steps
      void block(int attempt);
      void declaration();
      void param_list();
      void param();
      list<token*> ident_list(); //Returns a list of identifers (tokens)
      void statement_list();
      void statement();
      void compound_statement();
      void simple_statement();
      void if_statement();
      void while_statement();
      void for_statement();
      void loop_statement();
      void expr();
      void simple_expr();
      void expr2();
      void term();
      void factor();
      void primary();
      void range();
      void relop();
      void condition();
      
      //Checks if it should perform the function
      bool is_expr();
      bool is_relop();
      bool is_statement();
      bool is_declaration();

      //ID table
      void predefined_func(string name, lille_type start_t, lille_type ret_t); //Defines predefined functions
      void func_or_proc_call(id_table_entry* current_entry); //Handle function/proceedure calls and parameters
      lille_type get_type(); //Return the lille_type
      lille_type get_id_type(); //Return the lille_type
      id_table_entry* current_entry; //Keep track of current entry
      id_table_entry* current_funcproc; //Keep track of current function or proceedure
      id_table_entry* current_ident; //Keep track of the current identifier
     
};

#endif
   
