// Hannah Hunt
// SymTab Data Structure

#ifndef SYMTAB_IS_INCLUDED
#define SYMTAB_IS_INCLUDED

enum attribute_flags_t{ VAR, ARRAY, FUNCTION };

/*
 API for a symbol table. The symbol table stores (name, attribute) pairs. The data
 type for the attribute is void * so programs that use the symbol table can
 associate any attribute type with a name
 The symbol table is implemented using a separate chaining hash table.
*/

typedef struct attr {
    void* value;
    int type;
} attr_t;

//A SymEntry is the building block for linked lists of (name, attribute) pairs
typedef struct sym_entry_t {
    char *name;
    attr_t* attribute;
    struct sym_entry_t *next;
} sym_entry_t;  

/*
 Each symbol table is represented by a SymTab
 size is the current number of lists in the separate chaining hash table
 contents is an array of lists (i.e. points to the zeroth element in the array)
 if current is not NULL it points to the current (name,attribute)
 pair in the symbol table
*/
typedef struct {
    int size;
    sym_entry_t **contents;
    sym_entry_t *current;
} sym_tab_t;

sym_tab_t * create_sym_tab(int size);
/* PRE: size >= 0
 size is an estimate of the number of items that will be stored in the symbol
 table
 Return a pointer to a new symbol table
*/

//In the following functions assume a pre condition that table references a
//previously created symbol table
void destroy_sym_tab(sym_tab_t *table);
//recover space created by the symbol table functions
//no functions should use the symbol table after it is destroyed

int enter_name(sym_tab_t *table, char *name, int flag);
/*if name is not in the symbol table, a copy of name is added to the symbol table
 with a NULL attribute, set current to reference the new (name, attribute) pair
 and return 1
 if name is in the symbol table, set current to reference the (name, attribute)
 pair and return 0
*/

int find_name(sym_tab_t *table, char *name);
/*if name is in the symbol table, set current to reference the (name, attribute)
 pair and return 1
 otherwise do not change current and return 0
*/

int has_current(sym_tab_t *table);
//if current references a (name, attribute) pair return 1
//otherwise return 0;

void set_current_attr(sym_tab_t *table, void *attr);
//PRE: hashCurrent() == 1
//change the attribute value of the current (name, attribute) pair to attr

void *get_current_attr(sym_tab_t *table);
//PRE: hasCurrent() == 1
//return the attribute in the current (name, attribute) pair

char *get_current_name(sym_tab_t *table);
//PRE: hasCurrent() == 1
//return the name in the current (name, attribute) pair

//Assume no changes are made to the symbol table while iterating through the symbol table
int start_iterator(sym_tab_t *table);
//if the symbol table is empty, return 0
//otherwise set current to the "first" (name, attribute) pair in the symbol table and return 1

int next_entry(sym_tab_t *table);
/*if all (name, attribute) pairs have been visited since the last call to
 startIterator, return 0
 otherwise set current to the "next" (name, attribute) pair and return 1
*/
#endif