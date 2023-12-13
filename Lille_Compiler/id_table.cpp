/*
 * idtable.cpp
 *
 *  Created on: Jun 18, 2020
 *      Author: Michael Oudshoorn
 * Edited by Ryan Hirscher
 */



#include <iostream>
#include <string>

#include "id_table.h"
#include "token.h"
#include "error_handler.h"
#include "id_table_entry.h"
#include "lille_kind.h"
#include "lille_type.h"

using namespace std;

//Construct tree
id_table::id_table(error_handler* err)
{
    error = err;
    scope_level=0;
    for (int i =0; i< max_level; i++)
    {
       sym_table[i] = new node;
       sym_table[i]->left = NULL;
       sym_table[i]->right = NULL;
       sym_table[i]->idtbl = NULL;
    }
}

//Go into scope by adding
void id_table::enter_scope()
{
   scope_level++;
}
//Exit scope by subtracting
void id_table::exit_scope()
{
   scope_level--;
}
//Get scope
int id_table::get_scope()
{
   return scope_level;
}
//Start a tree and add an entry
void id_table::add_table_entry(id_table_entry* id)
{
   node* entry = new node;
   entry->left = NULL;
   entry->right = NULL;
   entry->idtbl = id;

   node* x = sym_table[get_scope()], * y = NULL;

   while (x->idtbl != NULL)
   {
      y = x;
      if (id->get_name() < x->idtbl->get_name())
      {
         x = x->left;
      }
      else
      {
         x = x->right;
      }
      if (x == NULL) //short circuit
         break;
   }

   if (y == NULL)
   {
      sym_table[get_scope()] = entry;
   }
   else if (id->get_name() < y->idtbl->get_name())
   {
      y->left = entry;
   }
   else
   {
       y->right = entry;
   }
  
   if (dbg_tbl)
   {
      cout << "Entry added: " << id->get_name() << " with scope: " << get_scope() << endl;
   }
}

//Pass onto id_table_entry
id_table_entry* id_table::enter_id(token* id, lille_type tip, lille_kind knd, int level, int offset, lille_type return_tip)
{
   return new id_table_entry(id, tip, knd, level, offset, return_tip);
}

//Look up an item in the ID table for a match
id_table_entry* id_table::lookup(string item)
{
   int scope = get_scope();
   node* ptr = sym_table[scope];
   
   while (scope >= 0)
   {
      if (ptr == NULL or ptr->idtbl == NULL)
      {
         if (scope > 0)
            ptr = sym_table[--scope];
         else
            scope--;
      }
      else if (item < ptr->idtbl->get_name())
         ptr = ptr->left;
      else if (item > ptr->idtbl->get_name())
         ptr = ptr->right;
      else if (item == ptr->idtbl->get_name())
      {
         if(dbg_tbl)
            cout << "FOUND ENTRY: " << item << " at type " << ptr->idtbl->get_type().to_string() << endl;
         return ptr->idtbl;
      }
   }
   if (dbg_tbl)
   {
      cout << "ENTRY NOT FOUND: " << item << endl;
      throw lille_exception("Invalid reference to: " + item);
   }
   return NULL;
}
//Look up an item in the ID table for a match (token)
id_table_entry* id_table::lookup(token* item)
{
   int scope = get_scope();
   node* ptr = sym_table[scope];

   while (scope >= 0)
   {
      if (ptr == NULL or ptr->idtbl == NULL)
      {
         if (scope > 0)
            ptr = sym_table[--scope];
         else
            scope--;
      }
      else if (item < ptr->idtbl->get_token_value())
         ptr = ptr->left;
      else if (item > ptr->idtbl->get_token_value())
         ptr = ptr->right;
      else if (item == ptr->idtbl->get_token_value())
      {
         if(dbg_tbl)
            cout << "FOUND ENTRY: " << item->to_string() << endl;
         return ptr->idtbl;
      }
   }
   if (dbg_tbl)
      cout << "ENTRY NOT FOUND: " << item->to_string() << endl;
   return NULL;
}

void id_table::dump_id_table(bool dump_all)
{
	node* ptr;
	if (!dump_all)
	{
		cout << "Dump of idtable for current scope only." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		
        	ptr = sym_table[get_scope()];
        	exit_scope();
        	delete ptr;
        	ptr = NULL;
	}
	else
	{
		cout << "Dump of the entire symbol table." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
		while ( get_scope() > 0 )
                {
                   ptr = sym_table[get_scope()];
                   cout << "SCOPE IS: " << get_scope() << endl;
                   cout << "LEFT:" << ptr->left << endl;
                   cout << "RIGHT:" << ptr->right << endl;
                   cout << "IDTBL:" << ptr->idtbl << endl;
                   exit_scope();
                   delete ptr;
                   ptr = NULL;
                }	
	}
}
