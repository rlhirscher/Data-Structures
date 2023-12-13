/*
 * idtable.h
 *
 *  Created on: Jun 18, 2020
 *      Author: Michael Oudshoorn
 *
 *  Edited by Ryan Hirscher
 */

#ifndef ID_TABLE_H_
#define ID_TABLE_H_

#include <iostream>
#include <string>

#include "token.h"
#include "id_table_entry.h"
#include "error_handler.h"
#include "lille_type.h"
#include "lille_kind.h"

using namespace std;

class id_table {
private:
	error_handler* error;
        bool dbg_tbl = {false};
        int scope_level;
        static const int max_level = 10;
      
        struct node {
           node* left;
           node* right;
           id_table_entry* idtbl;
        };
        node* sym_table[max_level];
        void add_table_entry(id_table_entry* id, node* ptr);

public:
    id_table(error_handler* err);

    //Scope is just increment/decrement and return
    void enter_scope();
    void exit_scope();
    int get_scope();

    //Search binary tree for item
    id_table_entry* lookup(string item);

    //Search binary tree for token
    id_table_entry* lookup(token* tok);

    //Add item into id_table
    void add_table_entry(id_table_entry* id);

    //Generate id_table_entry item
    id_table_entry* enter_id(token* id, lille_type tip, lille_kind knd, int level, int offset,
                             lille_type return_tip);
    

    void dump_id_table(bool dump_all = true);
};

#endif /* ID_TABLE_H_ */
