/*
 *   Ryan Hirscher
 *   CSC4510 Program Language Design/Translation
 *   Parser source
 *   12/8/2023
 *
 *   Final Submission
*/
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

#include "symbol.h"
#include "token.h"
#include "parser.h"
#include "error_handler.h"
#include "id_table.h"
#include "id_table_entry.h"
#include "lille_type.h"
#include "lille_kind.h"

//Constructor
//Sets the values passed in
parser::parser(scanner* scn, error_handler* err, id_table* t)
{
   scan=scn;
   error=err;
   table=t;
   checking = false;

   current_entry = NULL;
   current_ident = NULL;
   current_funcproc = NULL;
}
//Deconstructor
parser::~parser()
{
   delete scan;
   scan = NULL;

   delete table;
   table = NULL;
  
   delete error;
   error = NULL;

   delete current_entry;
   current_entry = NULL;
  
   delete current_ident;
   current_ident = NULL;
 
   delete current_funcproc;
   current_funcproc = NULL;
}
//Get type lille_type based on symbol
lille_type parser::get_type()
{
   switch (scan->this_token()->get_symbol()->get_sym())
   {
      case symbol::integer_sym:
         return lille_type::type_integer;
      case symbol::real_sym:
         return lille_type::type_real;
      case symbol::string_sym:
         return lille_type::type_string;
      case symbol::boolean_sym:
         return lille_type::type_boolean;
      default:
         return lille_type::type_unknown;
   }
}
 //Get type lille_type based on actual
lille_type parser::get_id_type()
{
   if(scan->have(symbol::integer))
      return lille_type::type_integer;
   else if(scan->have(symbol::real_num))
      return lille_type::type_real;
   else if(scan->have(symbol::strng))
      return lille_type::type_string;
   else if(scan->have(symbol::true_sym) or scan->have(symbol::false_sym))
      return lille_type::type_boolean;
   else 
      return lille_type::type_unknown;
}
//Defines predefined functions
void parser::predefined_func(string name, lille_type start_t, lille_type ret_t)
{
   token* func, *arg;
   symbol* sym;
   id_table_entry* funcID, *paramID;
   
   //Prepare and create entry for ID table
   sym = new symbol(symbol::identifier);
   func = new token(sym,0,0);
   func->set_identifier_value(name);
   funcID = table->enter_id(func, lille_type::type_func, lille_kind::unknown,0,0,start_t);
   table->add_table_entry(funcID);

   arg = new token(sym,0,0);
   arg->set_identifier_value("__" + name); //Storing predefined functions with 2 underscores
   paramID = new id_table_entry(arg, ret_t, lille_kind::value_param,0,0, lille_type::type_unknown);
   funcID->add_p(paramID);

}

//Start the scan
//This gets called to start the program
void parser::program()
{
   if (debgg)
      cout << "enter program()." << endl;
   scan->get_token();
   scan->must_be(symbol::program_sym);
   
   //Prepare and put program symbol into prog_value and id table
   symbol* sym = new symbol(symbol::program_sym);
   token* prog_name = new token(sym, 0, 0);
   prog_name->set_prog_value(scan->get_current_ident_name());
   id_table_entry* prog_id = table->enter_id(prog_name, lille_type::type_prog, lille_kind::unknown, table->get_scope(), 0, lille_type::type_unknown);
   table->add_table_entry(prog_id);
   current_entry = prog_id;

   scan->must_be(symbol::identifier);

   // Predefined functions
   parser::predefined_func("INT2REAL", lille_type::type_real, lille_type::type_integer);
   parser::predefined_func("REAL2INT", lille_type::type_integer, lille_type::type_real);
   parser::predefined_func("REAL2STRING", lille_type::type_string, lille_type::type_real);
   parser::predefined_func("INT2STRING", lille_type::type_string, lille_type::type_integer);
  

   //set_programName(scan->get_current_identifier_name);
   scan->must_be(symbol::is_sym);

   //Parse the block
   //1 indicates that this is the starting block for main
   block(1);

   //Check to see if concluding name matches program name
   if (scan->have(symbol::identifier) and prog_name->get_prog_value() != scan->get_current_ident_name())
   {
      scan->must_be(symbol::identifier);
      throw lille_exception("Program name does not match at end.");
   }
   else if (scan->have(symbol::identifier))
      scan->must_be(symbol::identifier);
   scan->must_be(symbol::semicolon_sym);

   //There cannot be excess after the end symbol
   if (!scan->is_end())
      error->flag(scan->this_token(), 77); 
   if (debgg)
      cout << "Exit program()." << endl;

}
//Parse the body of the program
//Expect variable declarations, function/proceedure declarations, and simple/compound statements
void parser::block(int attempt)
{
   //Find and process all variable declarations, functions and proceedure definitions
   //{ <declaration> }* begin <statement_list> end [ <ident> ]
   //0-many declarations
   if (debgg)
      cout << "enter block()." << endl;
   //Enter scope
   table->enter_scope();

   //While it is a declaration, call
   while (is_declaration())
      declaration();
   scan->must_be(symbol::begin_sym);

   //Parse the body
   statement_list();
   scan->must_be(symbol::end_sym);

   if(scan->have(symbol::identifier))
   {  
      if (attempt == 2)
         scan->must_be(symbol::identifier);
   }
   //Exit scope
   table->exit_scope();
   if (debgg)
      cout << "Exit block()." << endl;
} 

//DECLARE all variables functions, proceedures
void parser::declaration()
{
   
   if (debgg)
      cout << "enter declaration()." << endl;
   bool is_const = false;
   if (scan->have(symbol::identifier))
   {
     //1 or many identifiers separated by commas, then store them in a list of tokens
     list<token*> vars = ident_list();
     scan->must_be(symbol::colon_sym);
     lille_kind knd = lille_kind(lille_kind::variable);

     if (scan->have(symbol::constant_sym))
     {
        is_const = true;
        scan->must_be(symbol::constant_sym);
        knd = lille_kind(lille_kind::constant);        
     }
    
     //check type
     //This is literal. Must be a symbol named integer, real, string, or boolean
     lille_type cur_type = get_type();
     if (scan->have(symbol::string_sym))
        scan->must_be(symbol::string_sym);
     else if (scan->have(symbol::integer_sym))
        scan->must_be(symbol::integer_sym);
     else if (scan->have(symbol::real_sym))
        scan->must_be(symbol::real_sym);
     else if(scan->have(symbol::boolean_sym))
        scan->must_be(symbol::boolean_sym);
     else
        error->flag(scan->this_token(), 96);

     float r_val;
     int i_val;
     string s_val;
     bool b_val;

     //If it is a constant
     if (is_const)
     {
        if (scan->have(symbol::becomes_sym))
        {
           scan->must_be(symbol::becomes_sym);
           if (scan->have(symbol::strng))
           {
              s_val = scan->this_token()->get_string_value();
              if (!cur_type.is_type(lille_type::type_string))
                 error->flag(scan->this_token(), 111);
              scan->must_be(symbol::strng);
           }
           else if (scan->have(symbol::integer))
           {
              i_val = scan->this_token()->get_integer_value();
              if (!cur_type.is_type(lille_type::type_integer))
                 error->flag(scan->this_token(), 111);
              scan->must_be(symbol::integer);
           }
           else if (scan->have(symbol::real_num))
           {
              r_val = scan->this_token()->get_real_value();
              if (!cur_type.is_type(lille_type::type_real))
                 error->flag(scan->this_token(), 111);
              scan->must_be(symbol::real_num);
           }
           else if (scan->have(symbol::boolean_sym))
           {
              b_val = true ? scan->have(symbol::true_sym) : false;
              if (!cur_type.is_type(lille_type::type_boolean))
                 error->flag(scan->this_token(), 111);
              scan->must_be(symbol::boolean_sym);
           }
           else
              error->flag(scan->this_token(), 86);
        }
     }
     //Values gotten and stored if constant

     //Add to table
     id_table_entry* id;
     for (token* &v : vars)
     {
        //if token is not null
        if (v != NULL)
        {
           id = table->enter_id(v, cur_type, knd, table->get_scope(), 0, lille_type::type_unknown);
           if (is_const)
              id->const_val(i_val, r_val, s_val, b_val);
           table->add_table_entry(id);
        }
     }
     scan->must_be(symbol::semicolon_sym);
   } //End Identifier_list of declaration

   //Otherwise it is a function/proceedure (part of declaration)
   else 
   { 
      bool function_bool = false;
      //Proceedure
      if (scan->have(symbol::procedure_sym))
      {
         scan->must_be(symbol::procedure_sym);
         //Add procedure to the ID table
         symbol* sym = new symbol(symbol::procedure_sym);
         token* proc = new token(sym, 0, 0);
         proc->set_proc_value(scan->get_current_ident_name());
         id_table_entry* procID = table->enter_id(proc, lille_type::type_proc, lille_kind::unknown, table->get_scope(), 0, lille_type::type_unknown);
         table->add_table_entry(procID);
         current_funcproc = procID;

         scan->must_be(symbol::identifier);
      }  
      //Function
      else
      {
         function_bool = true;
         scan->must_be(symbol::function_sym);

         symbol* sym = new symbol(symbol::function_sym);
         token* func = new token(sym, 0, 0);
         func->set_func_value(scan->get_current_ident_name());
         id_table_entry* funcID = table->enter_id(func, lille_type::type_func, lille_kind::unknown, table->get_scope(), 0, lille_type::type_unknown);
         table->add_table_entry(funcID);
         current_funcproc = funcID;

         scan->must_be(symbol::identifier);
      }
      table->enter_scope();
      // [ ( <param_list> ) ] 
      if (scan->have(symbol::left_paren_sym))
      {
         scan->must_be(symbol::left_paren_sym);
         param_list();
         scan->must_be(symbol::right_paren_sym);
      }

      if (function_bool)
      {
         //If it is a function, there must be a return
         scan->must_be(symbol::return_sym);
         current_funcproc->const_return(get_type());
         //Type
         if (scan->have(symbol::string_sym))
            scan->must_be(symbol::string_sym);
         else if (scan->have(symbol::integer_sym))
            scan->must_be(symbol::integer_sym);
         else if (scan->have(symbol::real_sym))
            scan->must_be(symbol::real_sym);
         else if(scan->have(symbol::boolean_sym))
            scan->must_be(symbol::boolean_sym);
         else 
            error->flag(scan->this_token(), 96);
      }
      //Going into function/proceedure
      scan->must_be(symbol::is_sym);

      //Call block passing 2 indicating it is not main
      block(2);
      scan->must_be(symbol::semicolon_sym);
      current_entry = NULL;
      current_funcproc = NULL;
   }
   if (debgg)
      cout << "Exit declaration()." << endl;

}
void parser::param_list()
{
   // <param> { ; <param> }*
   //Assume one parameter
   if (debgg)
      cout << "enter param_list()." << endl;
   param();
   while (scan->have(symbol::semicolon_sym))
   {  
      scan->must_be(symbol::semicolon_sym); 
      param();
   }
   if (debgg)
      cout << "Exit param_list()." << endl;
}
void parser::param()
{
   if (debgg)
      cout << "enter param()." << endl;
   // <ident_list> : <param_kind> <type>
   // Get the list of tokens
   list<token*> vari = ident_list();
   id_table_entry* id;
   scan->must_be(symbol::colon_sym);
   lille_kind knd = lille_kind::unknown;
   //Parameter type
   if (scan->have(symbol::ref_sym))
   {
      scan->must_be(symbol::ref_sym);
      knd = lille_kind::ref_param;
   }
   else
   {
      scan->must_be(symbol::value_sym);
      knd = lille_kind::value_param;
   }
 
   lille_type tip = lille_type::type_unknown;
   //Get and store Type
   if (scan->have(symbol::string_sym))
   {
      tip = lille_type::type_string;
      scan->must_be(symbol::string_sym);
   }
   else if (scan->have(symbol::integer_sym))
   {
      tip = lille_type::type_integer;
      scan->must_be(symbol::integer_sym);
   }
   else if (scan->have(symbol::real_sym))
   {
      tip = lille_type::type_real;
      scan->must_be(symbol::real_sym);
   }
   else if (scan->have(symbol::boolean_sym))
   {
      tip = lille_type::type_boolean;
      scan->must_be(symbol::boolean_sym);
   }
   else
   {
      error->flag(scan->this_token(), 96);
   }

   //Enter into Id table for all identifiers in list of one parameter type and kind
   for (token* &vv : vari)
   {
      //if token is not null
      if (vv != NULL)
      {
         id = table->enter_id(vv, tip, knd, table->get_scope(), 0, lille_type::type_unknown);
         table->add_table_entry(id);
         current_funcproc->add_p(id);
      }
   }  

   if (debgg)
      cout << "Exit param()." << endl;

}
list<token*> parser::ident_list()
{
   if (debgg)
      cout << "enter ident_list()." << endl;
   list<token*> vars;
   //<ident> { , <ident> }*
   // 1 to many identifiers separated by commas
   //Add variable into the list
   vars.push_back(new token(new symbol(symbol::identifier),0,0));
   //Assign name to the token
   vars.back()->set_identifier_value(scan->get_current_ident_name());
   scan->must_be(symbol::identifier);
   while (scan->have(symbol::comma_sym))
   {
      scan->must_be(symbol::comma_sym);
      vars.push_back(new token(new symbol(symbol::identifier),0,0));
      vars.back()->set_identifier_value(scan->get_current_ident_name());
      scan->must_be(symbol::identifier);
   }
   return vars;
   if (debgg)
      cout << "Exit ident_list()." << endl;
}
void parser::statement_list()
{
   // <statement> ; { <statement> ; }*
   //Must have a statement followed by a semicolon
   // May be followed by the same
   if (debgg)
      cout << "enter statement_list()." << endl;
   statement();
   scan->must_be(symbol::semicolon_sym);
   while(is_statement())
   {
      statement();
      scan->must_be(symbol::semicolon_sym);
   }
   if (debgg)
      cout << "Exit statement_list()." << endl;
}

//Decides between compound and simple statement
void parser::statement()
{
   if (debgg)
      cout << "enter statement()." << endl;
   if (scan->have(symbol::if_sym) or scan->have(symbol::while_sym) or scan->have(symbol::for_sym) or scan->have(symbol::loop_sym))
      compound_statement();
   else
      simple_statement();
   if (debgg)
      cout << "Exit statement()." << endl;

}

//Decides which between if, while, for, and loop compound statements
void parser::compound_statement()
{
   if (debgg)
      cout << "enter compound_statement()." << endl;
   if (scan->have(symbol::if_sym))
      if_statement();
   else if (scan->have(symbol::while_sym))
      while_statement();
   else if (scan->have(symbol::for_sym))
      for_statement();
   else
      loop_statement();
   if (debgg)
      cout << "Exit compound_statement()." << endl;
}
//Handles functions and proceedure calls within statements
void parser::func_or_proc_call(id_table_entry* current_entry)
{

   bool left = false;
   if (scan->have(symbol::left_paren_sym))
   {
      scan->must_be(symbol::left_paren_sym);
      left = true;
   }
   //We know that get_type is function or proceedure
   string current_entry_name = current_entry->get_name();
   //Function Call
   if (current_entry->get_type().is_type(lille_type::type_func))
   {
      // From 0 to number of paramenters
      for (int i=0; i < current_entry->get_p_count(); i++)
      {
          if (scan->have(symbol::identifier))
          {
             //Check type
             current_ident = table->lookup(scan->get_current_ident_name());
             if (current_ident->get_type().is_type(lille_type::type_func))
             {
                if (current_entry->parameters(i)->get_kind().is_kind(lille_kind::ref_param))
                   error->flag(scan->this_token(), 123);
                if (not current_entry->parameters(i)->get_type().is_type(current_ident->return_tip()))
                   throw lille_exception("Identifier " + current_ident->get_name() + " Does not match parameter type in " + current_entry_name);
             }
             else if (not current_entry->parameters(i)->get_type().is_type(current_ident->get_type()))
                throw lille_exception("Identifier " + current_ident->get_name() + " Does not match parameter type in " + current_entry_name);
             scan->must_be(symbol::identifier);
          }
          else
          {
             if (not current_entry->parameters(i)->get_type().is_type(get_id_type()))
                throw lille_exception("Value does not match parameter type in " + current_entry_name);
             if (scan->have(symbol::integer))
                scan->must_be(symbol::integer);
             else if (scan->have(symbol::real_num))
                scan->must_be(symbol::real_num);
             else if (scan->have(symbol::strng))
                scan->must_be(symbol::strng);
             else if (scan->have(symbol::true_sym))
                scan->must_be(symbol::true_sym);
             else if (scan->have(symbol::false_sym))
                scan->must_be(symbol::false_sym);
             else
                throw lille_exception("Invalid type.");
          }
          if (scan->have(symbol::comma_sym))
             scan->must_be(symbol::comma_sym);
      }
   }
   //Proceedure Call
   //Matches function handle
   if (current_entry->get_type().is_type(lille_type::type_proc))
   {
      for (int i=0; i < current_entry->get_p_count(); i++)
      {
         if(scan->have(symbol::identifier))
         {
            current_ident = table->lookup(scan->get_current_ident_name());
            if(current_ident->get_kind().is_kind(lille_kind::value_param) and current_entry->parameters(i)->get_kind().is_kind(lille_kind::ref_param))
               error->flag(scan->this_token(), 98);
            else if(current_ident->get_type().is_type(lille_type::type_func))
            {
               if(current_entry->parameters(i)->get_kind().is_kind(lille_kind::ref_param))
                  error->flag(scan->this_token(), 123);
               if(not current_entry->parameters(i)->get_type().is_type(current_ident->return_tip()))
                  throw lille_exception("Identifier " + current_ident->get_name() + " Does not match parameter type in " + current_entry_name);
            }
            else if(not current_entry->parameters(i)->get_type().is_type(current_ident->get_type()))
               throw lille_exception("Identifier " + current_ident->get_name() + " Does not match parameter type in " + current_entry_name);

            scan->must_be(symbol::identifier);
         }
         else
         {
            if(not current_entry->parameters(i)->get_type().is_type(get_id_type())) 
               throw lille_exception("Value does not match parameter type in " + current_entry_name);
            if(scan->have(symbol::integer))
               scan->must_be(symbol::integer);
            else if(scan->have(symbol::real_num))
               scan->must_be(symbol::real_num);
            else if(scan->have(symbol::strng))
               scan->must_be(symbol::strng);
            else if(scan->have(symbol::true_sym))
               scan->must_be(symbol::true_sym);
            else if(scan->have(symbol::false_sym))
               scan->must_be(symbol::false_sym);
            else
               throw lille_exception("Invalid type.");
         }
            if(scan->have(symbol::comma_sym))
               scan->must_be(symbol::comma_sym);
      }  
   }
   //Parens
   if (left)
      scan->must_be(symbol::right_paren_sym);
}

//How to handle simple statements
void parser::simple_statement()
{
   if (debgg)
      cout << "enter simple_statement()." << endl;
   // <ident> [ ( <expr> { , <expr> }* ) ]
   // Identifier may be followed by nothing, or expression list in parens separated by commas
   if (scan->have(symbol::identifier))
   {
      string current_entry_name = scan->get_current_ident_name();
      current_entry = table->lookup(current_entry_name);

      if (current_entry == NULL)
      {
         error->flag(scan->this_token(), 81);
         throw lille_exception("Identifier not previously declared.");
      }
      else if (current_entry->get_type().is_type(lille_type::type_prog))
      {
         error->flag(scan->this_token(), 91);
      }

      scan->must_be(symbol::identifier);

      //If paren then this is a function/proceedure call
      if(scan->have(symbol::left_paren_sym))
      {
         scan->must_be(symbol::left_paren_sym);
         if (current_entry->get_type().is_type(lille_type::type_func) or current_entry->get_type().is_type(lille_type::type_proc))
            func_or_proc_call(current_entry);
         scan->must_be(symbol::right_paren_sym);
      }
      // <ident> := <expr>
      else if (scan->have(symbol::becomes_sym))
      {
         scan->must_be(symbol::becomes_sym);

         if (current_entry == NULL)
            error->flag(scan->this_token(), 81);

         if (current_entry->get_kind().is_kind(lille_kind::for_ident))
            error->flag(scan->this_token(), 85);
 
         if (current_entry->get_kind().is_kind(lille_kind::value_param))
            error->flag(scan->this_token(), 85);
         checking = true;
         expr();
         checking = false;
      }
   }

   else if (scan->have(symbol::exit_sym))
   {
      // exit [ when <expr> ]
      scan->must_be(symbol::exit_sym);
      //If it has a when and expression
      if (scan->have(symbol::when_sym))
      {
         scan->must_be(symbol::when_sym);
         // Make sure indent given is an integer
         current_ident = table->lookup(scan->get_current_ident_name());
         if(not current_ident->get_type().is_type(lille_type::type_integer))
            throw lille_exception("Exit condition must be an integer type");
         scan->must_be(symbol::identifier);
         if (scan->have(symbol::greater_than_sym)) 
            scan->must_be(symbol::greater_than_sym);
         else if (scan->have(symbol::less_than_sym)) 
            scan->must_be(symbol::less_than_sym);
         else if (scan->have(symbol::equals_sym)) 
            scan->must_be(symbol::equals_sym);
         else if (scan->have(symbol::not_equals_sym)) 
            scan->must_be(symbol::not_equals_sym);
         else if (scan->have(symbol::less_or_equal_sym)) 
            scan->must_be(symbol::less_or_equal_sym);
         else if (scan->have(symbol::greater_or_equal_sym))
            scan->must_be(symbol::greater_or_equal_sym);
         else
            throw lille_exception("Expected a logical symbol (> < <> = >= <=)");
         // Make sure next ident is also an integer
         if(scan->have(symbol::identifier))
         {
            current_ident = table->lookup(scan->get_current_ident_name());
            if(not current_ident->get_type().is_type(lille_type::type_integer))
               throw lille_exception("Exit condition must be an integer type");
            scan->must_be(symbol::identifier);
         }
         else 
            scan->must_be(symbol::integer);
      }
   }
   else if (scan->have(symbol::return_sym))
   {
      // return [ <expr> ]
      scan->must_be(symbol::return_sym);
      while (is_expr())
      {
         // Make sure the identifier given is the functions return type
         if(scan->have(symbol::identifier)) 
         {
            id_table_entry* current_return_ident = table->lookup(scan->get_current_ident_name());
            if(not current_funcproc->get_type().is_type(lille_type::type_func))
               throw lille_exception("Return in non-function");
            else if(current_return_ident->get_type().is_equal(lille_type::type_func))
            {
               if(not current_funcproc->return_tip().is_type(current_return_ident->return_tip()))
                  throw lille_exception("ERROR: Function return value is " + current_funcproc->return_tip().to_string() + " but given " + current_return_ident->get_type().to_string());
            }
            else if (not current_funcproc->return_tip().is_type(current_return_ident->get_type()))
               throw lille_exception("Function return value is " + current_funcproc->return_tip().to_string() + " but given " + current_return_ident->get_type().to_string());
            scan->must_be(symbol::identifier);
         }
         // Else if a number given is of functions return type
         else if(scan->have(symbol::integer) or scan->have(symbol::real_num))
         {
            if(scan->have(symbol::integer))
            {
               if(not current_funcproc->return_tip().is_type(lille_type::type_integer))
                  throw lille_exception("Function return value is " + current_funcproc->get_type().to_string() + " but given Integer");
               scan->must_be(symbol::integer);
            }
            if(scan->have(symbol::real_num))
            {
               if(not current_funcproc->return_tip().is_type(lille_type::type_real))
                  throw lille_exception("Function return value is " + current_funcproc->get_type().to_string() + " but given Real Number");
               scan->must_be(symbol::real_num);
            }
         }
         // Else if a boolean given is of functions return type
         else if(scan->have(symbol::true_sym) or scan->have(symbol::false_sym))
         {
            if(scan->have(symbol::true_sym)) 
               scan->must_be(symbol::true_sym);
            else if(scan->have(symbol::false_sym)) 
               scan->must_be(symbol::false_sym);
            if(not current_funcproc->get_type().is_type(lille_type::type_integer))
               throw lille_exception("Function return value is " + current_funcproc->get_type().to_string() + " but given Boolean");
         }
         // Else if a string given is of functions return type
         else if(scan->have(symbol::strng))
         {
            if(not current_funcproc->get_type().is_type(lille_type::type_integer))
               throw lille_exception("Function return value is " + current_funcproc->get_type().to_string() + " but given String");
            scan->must_be(symbol::strng);
         }
         else 
            throw lille_exception("Function return is " + current_funcproc->get_type().to_string() + " but given Unknown");
        
         if(scan->have(symbol::plus_sym) or scan->have(symbol::minus_sym))
         {
            if (scan->have(symbol::plus_sym)) 
                scan->must_be(symbol::plus_sym);
            else 
                scan->must_be(symbol::minus_sym);
         }
         else if(scan->have(symbol::asterisk_sym) or scan->have(symbol::slash_sym))
         {
            if (scan->have(symbol::asterisk_sym)) 
               scan->must_be(symbol::asterisk_sym);
            else 
               scan->must_be(symbol::slash_sym);
         }
      }
   }
   else if (scan->have(symbol::read_sym))
   {
      // read [ ( ] <ident> { , <ident> }* [ ) ]
      // Read symbol may be followed by a left paren
      // then must have an identifier and may be a list separated by commas
      // can be closed with a right paren if there is a left
      scan->must_be(symbol::read_sym);
      bool left=false;
      if (scan->have(symbol::left_paren_sym)) 
      {
         left=true;
         scan->must_be(symbol::left_paren_sym); 
      }
      current_ident = table->lookup(scan->get_current_ident_name());
      if (current_ident == NULL)
         throw lille_exception("Undeclared variable " + scan->get_current_ident_name());
      scan->must_be(symbol::identifier);
      while(scan->have(symbol::comma_sym))
      {
         scan->must_be(symbol::comma_sym);
         current_ident = table->lookup(scan->get_current_ident_name());
         if (current_ident == NULL)
            throw lille_exception("Undeclared variable " + scan->get_current_ident_name());
         scan->must_be(symbol::identifier);
      }
      if (scan->have(symbol::right_paren_sym))
      {
         //Has a right paren but no left paren
         if (left == false)
            error->flag(scan->this_token(), 20);
         scan->must_be(symbol::right_paren_sym); 
      }
      //Has a left paren but no right paren
      else if (left == true)
      {
         error->flag(scan->this_token(), 21);
      }
   }
   else if (scan->have(symbol::write_sym))
   {
      // write [ ( ] <expr> { , <expr> }* [ ) ]
      // Write symbol may be followed by a paren
      // Must have one expr which may be followed by a comma and many expr
      //Closed by a right paren if there is a left
      scan->must_be(symbol::write_sym);
      bool left=false;
      if (scan->have(symbol::left_paren_sym))
      {
         left=true;
         scan->must_be(symbol::left_paren_sym);
      }
      if (!is_expr())
         throw lille_exception("Expected expression."); 
      bool look = true;
      do
      {
         if(scan->have(symbol::identifier))
         {
            current_ident = table->lookup(scan->get_current_ident_name());
            scan->must_be(symbol::identifier);
            if(current_ident->get_type().is_type(lille_type::type_func) or current_ident->get_type().is_type(lille_type::type_proc))
               func_or_proc_call(current_ident);
         }
         else if(scan->have(symbol::strng))
            scan->must_be(symbol::strng);
         if(scan->have(symbol::ampersand_sym))
         {
            scan->must_be(symbol::ampersand_sym);
            look = true;
         }   
         else if(scan->have(symbol::comma_sym))
         {
            scan->must_be(symbol::comma_sym);
            look = true;
         }
         else 
            look = false;
      } while(look);

      if (scan->have(symbol::right_paren_sym))
      {
         //Has a right paren but no left paren
         if (left == false)
            error->flag(scan->this_token(), 20);
         scan->must_be(symbol::right_paren_sym);
      }
      //Has a left paren but no right paren
      else if (left == true)
      {
         error->flag(scan->this_token(), 21);
      }
   }
   else if (scan->have(symbol::writeln_sym))
   {
      // writeln [ ( ] [ <expr> { , <expr> }* ] [ ) ]
      scan->must_be(symbol::writeln_sym);
      bool left=false;
      if (scan->have(symbol::left_paren_sym))
      {
         left=true;
         scan->must_be(symbol::left_paren_sym);
      }
      bool look = true;
      //Expr is optional and can be a list separated by a comma
      if (is_expr())
      {
         do
         {
            if(scan->have(symbol::identifier))
            {
               current_ident = table->lookup(scan->get_current_ident_name());
               scan->must_be(symbol::identifier);
               if(current_ident->get_type().is_type(lille_type::type_func) or current_ident->get_type().is_type(lille_type::type_proc))
                  func_or_proc_call(current_ident);
            }
            else if(scan->have(symbol::strng))
               scan->must_be(symbol::strng);
            if(scan->have(symbol::ampersand_sym))
            {
               scan->must_be(symbol::ampersand_sym);
               look = true;
            }
            else if(scan->have(symbol::comma_sym))
            {
               scan->must_be(symbol::comma_sym);
               look = true;
            }
            else
               look = false;
         } while(look);
      }
      if (scan->have(symbol::right_paren_sym))
      {
         //Has a right paren but no left paren
         if (left == false)
            error->flag(scan->this_token(), 20);
         scan->must_be(symbol::right_paren_sym);
      }
      //Has a left paren but no right paren
      else if (left == true)
      {
         error->flag(scan->this_token(), 21);
      }
   }
   //NULL
   else
      scan->must_be(symbol::null_sym);
   current_entry = NULL;
   if (debgg)
      cout << "Exit simple_statement()." << endl;
}
void parser::if_statement()
{
   // if <expr> then <statement_list>
   // { elsif <expr> then <statement_list> }*
   // [ else <statement_list> ]
   // end if
   //If symbol must be followed by expression, then, statement list
   //and may be followed by elseif or else 
   //If statement ends with end and if symbols
   if (debgg)
      cout << "enter if_statement()." << endl;
   scan->must_be(symbol::if_sym);
   condition();
   scan->must_be(symbol::then_sym);
   statement_list();
   //0 to many else if statements
   while (scan->have(symbol::elsif_sym))
   {
      scan->must_be(symbol::elsif_sym);
      condition();
      scan->must_be(symbol::then_sym);
      statement_list();
   }
   if (scan->have(symbol::else_sym))
   {
      scan->must_be(symbol::else_sym);
      statement_list();
   }
   scan->must_be(symbol::end_sym);
   scan->must_be(symbol::if_sym);
   if (debgg)
      cout << "Exit if_statement()." << endl;
}
//Handle the conditionals of if/elseif and while/for loops
void parser::condition()
{
   bool and_or = false;
   do
   {
      if(scan->have(symbol::identifier))
      {
         //FIRST PART OF CONDITION
         id_table_entry* first = table->lookup(scan->get_current_ident_name());
         if(first == NULL)
            throw lille_exception("Undeclared identifier " + scan->get_current_ident_name());
         scan->must_be(symbol::identifier);
         if(is_relop())
         {
            if (scan->have(symbol::greater_than_sym)) 
               scan->must_be(symbol::greater_than_sym);
            else if (scan->have(symbol::less_than_sym)) 
               scan->must_be(symbol::less_than_sym);
            else if (scan->have(symbol::equals_sym)) 
               scan->must_be(symbol::equals_sym);
            else if (scan->have(symbol::not_equals_sym)) 
               scan->must_be(symbol::not_equals_sym);
            else if (scan->have(symbol::less_or_equal_sym)) 
               scan->must_be(symbol::less_or_equal_sym);
            else if (scan->have(symbol::greater_or_equal_sym))
               scan->must_be(symbol::greater_or_equal_sym);
            else
               throw lille_exception("Expected a logical symbol (> < <> = >= <=)");

            //SECOND PART OF CONDITION
            id_table_entry* second = table->lookup(scan->get_current_ident_name());
            if(scan->have(symbol::identifier))
            {
               if(second == NULL)
                  throw lille_exception("Undeclared identifier " + scan->get_current_ident_name());
               if(not first->get_type().is_type(second->get_type()))
               {
                  throw lille_exception("Cannot compare different types");
               }
            }
            else if(scan->have(symbol::integer) or scan->have(symbol::real_num))
            {
               if(not first->get_type().is_type(second->get_type()))
               {
                  throw lille_exception("Cannot compare different types");
               }
               if(scan->have(symbol::integer))
                  scan->must_be(symbol::integer);
               else
                  scan->must_be(symbol::real_num);
            }
            else if(scan->have(symbol::true_sym))
               scan->must_be(symbol::true_sym);
            else if(scan->have(symbol::false_sym))
               scan->must_be(symbol::false_sym);
            else 
               throw lille_exception("Invalid argument for loop");
         }
         else if(not first->get_type().is_type(lille_type::type_boolean))
            throw lille_exception("Invalid argument for loop");
      }
      else if(scan->have(symbol::true_sym))
         scan->must_be(symbol::true_sym);
      else if(scan->have(symbol::false_sym))
         scan->must_be(symbol::false_sym);
      else 
         throw lille_exception("Invalid argument for `if`");

      //Continue if and/or symbol
      if(scan->have(symbol::and_sym))
      {
         scan->must_be(symbol::and_sym);
         and_or = true;
      }
      else if(scan->have(symbol::or_sym))
      {
         scan->must_be(symbol::or_sym);
         and_or = true;
      }
      else 
         and_or = false;
   } while(and_or);
}
void parser::while_statement()
{
   if (debgg)
      cout << "enter while_statement()." << endl;
   // while <expr> <loop_statement>
   // while must be followed by expression and loop statement
   scan->must_be(symbol::while_sym);
   condition();
   loop_statement();
   if (debgg)
      cout << "Exit while_statement()." << endl;
}
void parser::for_statement()
{
   // for <ident> in [ reverse ] <range> <loop_statement>
   //for must be followed by identifer and in which may be followed by reverse
   // Then a range and loop statement
   if (debgg)
      cout << "enter for_statement()." << endl;
   scan->must_be(symbol::for_sym);
 
   //Prepare and enter into table
   symbol* sym = new symbol(symbol::identifier);
   token* tok = new token(sym,0,0);
   tok->set_identifier_value(scan->get_current_ident_name());
   id_table_entry* i_entry = table->enter_id(tok, lille_type::type_integer, lille_kind::for_ident, table->get_scope(), 0, lille_type::type_unknown);
   table->add_table_entry(i_entry);

   scan->must_be(symbol::identifier);
   scan->must_be(symbol::in_sym);
   if (scan->have(symbol::reverse_sym))
      scan->must_be(symbol::reverse_sym);
   scan->must_be(symbol::integer);
   scan->must_be(symbol::range_sym);
   scan->must_be(symbol::integer);
   loop_statement();
   if (debgg)
      cout << "Exit for_statement()." << endl;
}
void parser::loop_statement()
{
   if (debgg)
      cout << "enter loop_statement()." << endl;
   // loop <statement_list> end loop
   // loop must be followed by statement list, end, and loop
   scan->must_be(symbol::loop_sym);
   statement_list();
   scan->must_be(symbol::end_sym);
   scan->must_be(symbol::loop_sym);
   if (debgg)
      cout << "Exit loop_statement()." << endl;
}
void parser::expr()
{
   // <simple_expr> [ <relop> <simple_expr> ]
   // OR <simple_expr> in <range>
   // Simple expression may be followed by relop + another simple expression
   // Or simple expression may be followed by in symbol + range
   if (debgg)
      cout << "enter expr()." << endl;
   simple_expr();
   // > | < | = | <> | <= | >=
   if (is_relop())
   {
      //Must consume the symbol with must_be
      if (scan->have(symbol::greater_than_sym))
         scan->must_be(symbol::greater_than_sym);
      else if (scan->have(symbol::less_than_sym))
         scan->must_be(symbol::less_than_sym);
      else if (scan->have(symbol::equals_sym))
         scan->must_be(symbol::equals_sym);
      else if (scan->have(symbol::not_equals_sym))
         scan->must_be(symbol::not_equals_sym);
      else if (scan->have(symbol::less_or_equal_sym))
         scan->must_be(symbol::less_or_equal_sym);
      else if (scan->have(symbol::greater_or_equal_sym))
         scan->must_be(symbol::greater_or_equal_sym);
      simple_expr();
   }
   else if (scan->have(symbol::in_sym))
   {
      scan->must_be(symbol::in_sym);
      range();
   }
   if (debgg)
      cout << "Exit expr()." << endl;
}
void parser::simple_expr()
{
   // <expr2> { <stringop> <expr2> }*
   //Expr2 may be followed by 0 to many & + expr2
   if (debgg)
      cout << "enter simple_expr()." << endl;
   expr2();
   while (scan->have(symbol::ampersand_sym))
   {
      scan->must_be(symbol::ampersand_sym);
      expr2();
   }
   if (debgg)
      cout << "Exit simple_expr()." << endl;
}
void parser::expr2()
{
   // <term> { { <addop> | or } <term> }*
   //Term may be followed by 0 to many [+, -, or] + term
   if (debgg)
      cout << "enter expr2()." << endl;
   term();
   while (scan->have(symbol::plus_sym) or scan->have(symbol::minus_sym) or scan->have(symbol::or_sym))
   {
      if (scan->have(symbol::plus_sym))
         scan->must_be(symbol::plus_sym);
      else if (scan->have(symbol::minus_sym))
         scan->must_be(symbol::minus_sym);
      else
         scan->must_be(symbol::or_sym);
      if (not current_entry->get_type().is_type(lille_type::type_integer) and not current_entry->get_type().is_type(lille_type::type_real))
         throw lille_exception("Cannot add or subtract non-numbers");
      term();
   }
   if (debgg)
      cout << "Exit expr2()." << endl;
}
void parser::term()
{
   //<factor> { { <multop> | and } <factor> }*
   // Factor which may be followed by 0 to many [ /, *, and] + factor
   if (debgg)
      cout << "enter term()." << endl;
   factor();
   while(scan->have(symbol::asterisk_sym) or scan->have(symbol::slash_sym) or scan->have(symbol::and_sym))
   {
      if (scan->have(symbol::asterisk_sym))
         scan->must_be(symbol::asterisk_sym);
      else if (scan->have(symbol::slash_sym))
         scan->must_be(symbol::slash_sym);
      else
         scan->must_be(symbol::and_sym);
      if (not current_entry->get_type().is_type(lille_type::type_integer) and not current_entry->get_type().is_type(lille_type::type_real))
         throw lille_exception("Cannot multiply or devide non-numbers");
      factor();
   }
   if (debgg)
      cout << "Exit term()." << endl;
}
void parser::factor()
{
   // <primary> [ ** <primary> ] | [ <addop> ] <primary>
   //Primary which can be followed by a power symbol which needs another primary
   if (debgg)
      cout << "enter factor()." << endl;

   if (scan->have(symbol::minus_sym))
   {
      scan->must_be(symbol::minus_sym);
      primary(); 
      if (not current_entry->get_type().is_type(lille_type::type_integer) and not current_entry->get_type().is_type(lille_type::type_real))
         throw lille_exception("Cannot addop (-) non-numbers");
   }
   else if (scan->have(symbol::plus_sym))
   {
      scan->must_be(symbol::plus_sym);
       primary();
   }
   primary();
   if (scan->have(symbol::power_sym))
   {
      if (not current_entry->get_type().is_type(lille_type::type_integer) and not current_entry->get_type().is_type(lille_type::type_real))
         throw lille_exception("Must be raised to the power of a number");
      scan->must_be(symbol::power_sym);
      primary();
   }
   if (debgg)
      cout << "Exit factor()." << endl;
}
void parser::primary()
{
   if (debgg)
      cout << "enter primary()." << endl;
   // not <expr>
   if (scan->have(symbol::not_sym))
   {
      if (not current_entry->get_type().is_type(lille_type::type_boolean))
         throw lille_exception("Cannot use operator 'not' in a non-boolean");
      scan->must_be(symbol::not_sym);
      expr();
   }
   // odd <expr>
   else if (scan->have(symbol::odd_sym))
   {
      scan->must_be(symbol::odd_sym);
      expr();
   }
   // ( <simple_expr> )
   else if (scan->have(symbol::left_paren_sym))
   {
      scan->must_be(symbol::left_paren_sym);
      simple_expr();
      scan->must_be(symbol::right_paren_sym);
   }
   // <ident> [ ( <expr>{ , <expr> }* ) ]
   // Identifier which may be followed by 0 or many expressions separated by commas
   else if (scan->have(symbol::identifier))
   {
      string current_entry_name = scan->get_current_ident_name();
      current_entry = table->lookup(current_entry_name);

      if (current_entry == NULL)
      {
         error->flag(scan->this_token(), 81);
         throw lille_exception("Identifier not previously declared.");
      }
      else if (current_entry->get_type().is_type(lille_type::type_prog))
      {
         error->flag(scan->this_token(), 91);
      }
      
      scan->must_be(symbol::identifier);

      if (scan->have(symbol::left_paren_sym))
      {
         scan->must_be(symbol::left_paren_sym);
         if (current_entry->get_type().is_type(lille_type::type_func) or current_entry->get_type().is_type(lille_type::type_proc))
            func_or_proc_call(current_entry);
         else
            error->flag(scan->this_token(), 121);
         scan->must_be(symbol::right_paren_sym);
      }

   }
   // Number
   else if (scan->have(symbol::real_num) or scan->have(symbol::integer))
   {
      if (checking == false)
      {
         if (scan->have(symbol::real_num))
            scan->must_be(symbol::real_num);
         else
            scan->must_be(symbol::integer);
      }
      else if (checking == true)
      {
         //type check for number
         lille_type tip;
         string current_entry_name = scan->get_current_ident_name();
         current_entry = table->lookup(current_entry_name);
         if (scan->have(symbol::real_num))
            tip = lille_type::type_real;
         else
            tip = lille_type::type_integer;
         if (not current_entry->get_type().is_type(tip))
            throw lille_exception("Value given does not match the type of " + current_entry_name);
         if (scan->have(symbol::real_num))
            scan->must_be(symbol::real_num);
         else if (scan->have(symbol::integer))
            scan->must_be(symbol::integer);
      }
   }
   // String type check
   else if (scan->have(symbol::strng))
   {
      if (checking == false)
         scan->must_be(symbol::strng);
      else if (checking == true)
      { 
         lille_type tip = lille_type::type_string;
         string current_entry_name = scan->get_current_ident_name();
         current_entry = table->lookup(current_entry_name);
         if (not current_entry->get_type().is_type(tip))
            throw lille_exception("Value given does not match the type of " + current_entry_name);
         scan->must_be(symbol::strng);
      }

   }
   // Must be a boolean
   else if (scan->have(symbol::true_sym) or scan->have(symbol::false_sym))
   {
      if (checking == false)
      {
         if (scan->have(symbol::false_sym))
            scan->must_be(symbol::false_sym);
         else
            scan->must_be(symbol::true_sym);
      }
      else if (checking == true)
      {
         lille_type tip = lille_type::type_boolean;
         string current_entry_name = scan->get_current_ident_name();
         current_entry = table->lookup(current_entry_name);
         if (not current_entry->get_type().is_type(tip))
            throw lille_exception("Value given does not match the type of " + current_entry_name);
         if (scan->have(symbol::false_sym))
            scan->must_be(symbol::false_sym);
         else
            scan->must_be(symbol::true_sym);
      }
   }
   else
      error->flag(scan->this_token(), 84);
   if (debgg)
      cout << "Exit primary()." << endl;
}
void parser::range()
{
   if (debgg)
      cout << "enter range()." << endl;
   // Simple expression .. simple expression
   simple_expr();
   scan->must_be(symbol::range_sym);
   simple_expr();
   if (debgg)
      cout << "Exit range()." << endl;
}
void parser::relop()
{
   if (debgg)
      cout << "enter relop()." << endl;
   // > | < | = | <> | <= | >=
   if (scan->have(symbol::greater_than_sym))
      scan->must_be(symbol::greater_than_sym);
   else if (scan->have(symbol::less_than_sym))
      scan->must_be(symbol::less_than_sym);
   else if (scan->have(symbol::equals_sym))
      scan->must_be(symbol::equals_sym);
   else if (scan->have(symbol::not_equals_sym))
      scan->must_be(symbol::not_equals_sym);
   else if (scan->have(symbol::less_or_equal_sym))
      scan->must_be(symbol::less_or_equal_sym);
   else
      scan->must_be(symbol::greater_or_equal_sym);
   if (debgg)
      cout << "Exit relop()." << endl;
}
//Is functions return true if symbol is part of a the section
bool parser::is_expr()
{
   if (scan->have(symbol::not_sym) or scan->have(symbol::odd_sym) or scan->have(symbol::left_paren_sym) or scan->have(symbol::identifier) or scan->have(symbol::integer) or scan->have(symbol::real_sym) or scan->have(symbol::strng) or scan->have(symbol::true_sym) or scan->have(symbol::false_sym) or scan->have(symbol::plus_sym) or scan->have(symbol::minus_sym) or scan->have(symbol::asterisk_sym) or scan->have(symbol::slash_sym))
      return true;
   else
      return false;
}
bool parser::is_relop()
{
   // > | < | = | <> | <= | >=
   if (scan->have(symbol::greater_than_sym) or scan->have(symbol::less_than_sym) or scan->have(symbol::equals_sym) or scan->have(symbol::not_equals_sym) or scan->have(symbol::less_or_equal_sym) or scan->have(symbol::greater_or_equal_sym))
      return true;
   else
      return false; 
}
bool parser::is_statement()
{
   if (scan->have(symbol::identifier) or scan->have(symbol::exit_sym) or scan->have(symbol::return_sym) or scan->have(symbol::read_sym) or scan->have(symbol::write_sym) or scan->have(symbol::writeln_sym) or scan->have(symbol::null_sym) or scan->have(symbol::if_sym) or scan->have(symbol::loop_sym) or scan->have(symbol::for_sym) or scan->have(symbol::while_sym))
      return true;
   else
      return false;
}
bool parser::is_declaration()
{
   if (scan->have(symbol::identifier) or scan->have(symbol::procedure_sym) or scan->have(symbol::function_sym))
      return true;
   else
      return false;
}

