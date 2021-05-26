#include "SymTab.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// HELPER FUNCTION DEFS -------------------------------------
int             next_prime_number(int number);
int             is_prime_number(int number);
unsigned long   hash(char *str, int size);
sym_entry_t*    create_entry(sym_tab_t* table, char* name, int type);
void            free_list(sym_entry_t* startNode);

int current_is_array(sym_tab_t* table);
void set_current_is_array(sym_tab_t* table, int bool);

// -----------------------------------------------------------

sym_tab_t * create_sym_tab(int size){
    if(size <= 0 ){
        return NULL;
    } 
    size = next_prime_number(size);

    sym_tab_t* table = (sym_tab_t*)malloc(sizeof(sym_tab_t)); 
    assert(table);

    table->contents = (sym_entry_t**)malloc(sizeof(sym_entry_t**) * size); 
    assert(table->contents);

    table->size = size;
    table->current = NULL;

    int i;
    for(i = 0; i < table->size; i++){
        table->contents[i] = NULL;
    }

    return table;
}

void destroysym_tab_t(sym_tab_t *table){
    int i;
    for(i = 0; i < table->size; i++ ) {
        if( table->contents[i] ) {
            free_list( table->contents[i] );
        }
    }
    free(table);
}

int enter_name(sym_tab_t *table, char *name, int type){
    int hash_index = hash(name, table->size);

    table->current = table->contents[hash_index];

    while(table->current){
        if(strcmp(table->current->name, name) == 0){
            return 0;
        } 

        table->current = table->current->next;
    }

    create_entry(table, name, type);
    return 1;
}

int find_name(sym_tab_t *table, char *name){
    int index = hash(name, table->size);

    if( table->contents[index] ) {
        table->current = table->contents[index];

        while (table->current) {
            if(strcmp(table->current->name, name) == 0){
                return 1;
            }

            table->current = table->current->next;
        }
    }
    return 0;
}

int has_current(sym_tab_t *table){
    if( table->current ){
        return 1;
    } else {
        return 0;
    }
}

void set_current_attr(sym_tab_t *table, void * attr){
    if( has_current(table) ){
        table->current->attribute = attr;
    }
}

void * get_current_attr(sym_tab_t *table){
    if( has_current(table) ){
        return table->current->attribute;
    } 

    return NULL;
}

char * get_current_name(sym_tab_t *table){
    if( has_current(table) ){
        return table->current->name;
    }
    
    return NULL;
}

int start_iterator(sym_tab_t *table){
    if( table->size > 0 ){
        int i;
        for( i = 0; i < table->size; i++){
            if( table->contents[i] ){
                table->current = table->contents[i];
                return 1;
            }
        } 
        return 0;
    } else {
        return 0;
    } 
}

int next_entry(sym_tab_t *table){
    int i;
    int index = hash(table->current->name, table->size);

    if( table->current->next ) {
        table->current = table->current->next;
        return 1;
    } else {
        for( i = index + 1; i < table->size; i++){
            if( table->contents[i] ){
                table->current = table->contents[i];
                return 1;
            }
        }
        return 0;
    }
}

// HELPER FUNCTIONS ------------------------------------------------------
int next_prime_number(int number){
    if( is_prime_number(number) == 1 ){
        return number;
    } else {
        return next_prime_number(number + 1);
    }
}

int is_prime_number(int number){
    int b;

    for( b = 2; b < number; b++) {
        if (number % b == 0) {
            return 0;
        }
    }
    return 1;
}

sym_entry_t* create_entry(sym_tab_t* table, char* name, int type ){
    int index = hash(name, table->size);

    // allocating memory for a new entry
    sym_entry_t* entry = (sym_entry_t*)malloc(sizeof(sym_entry_t)); 
    assert(entry);
    
    //filling entry data
    entry->attribute = (attr_t*)malloc(sizeof(attr_t));
    entry->attribute->type = type;
    entry->attribute->value = NULL;
    entry->next = NULL;
    entry->name = strdup(name);

    table->current = entry;

    if( table->contents[index] ){
        entry->next = table->contents[index];
        table->contents[index] = entry;
    } else {       
        table->contents[index] = entry;
    }
    
    return entry;
}

void free_list(sym_entry_t* startNode){
    sym_entry_t* currentNode = startNode;
    sym_entry_t* nextNode = currentNode->next;

    while( currentNode ){

        free(currentNode->name);
        free(currentNode);

        currentNode = nextNode;
        if( currentNode ){
            nextNode = currentNode->next;
        }
    }
}

unsigned long hash(char *str, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)){
        hash = ((hash << 5) + hash) + c; 
    }

    return hash % size;
}

int current_is_array(sym_tab_t* table){
    if( has_current(table) ){
        return table->current->attribute->type;
    } else {
        return 0;
    }
}

void set_current_is_array(sym_tab_t* table, int bool){
    if(has_current(table)){
        table->current->attribute->type = bool;
    }
}