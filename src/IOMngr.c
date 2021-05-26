#include "IOMngr.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

extern int errno;

static FILE * src_file       = NULL;
static FILE * listing_file   = NULL;

static char *   current_line       = NULL;
static int      current_line_number = 0;
static int      current_column     = -1;

// HELPER FUNCTION DEFS ---------------------------------------------
int print_char(char c, FILE *listing_file, int is_number);
int has_next_char(char* current_line, int current_index);

// OPENING / CLOSING FILES ------------------------------------------------------------------------------------
int open_files(char * source_file_name, char * listing_file_name){
    printf("name -> %s\n", source_file_name);
    errno = 0;

    src_file = (FILE *)malloc(sizeof(FILE));
    assert(src_file && printf("Please provide a file to compile.\n"));
    
    src_file = fopen( source_file_name , "r");
    if( listing_file_name ){
        listing_file = (FILE *)malloc(sizeof(FILE));
        assert(src_file);

        listing_file = fopen( listing_file_name , "w");
    }

    if( !src_file || errno != 0 ){
        return 0;
    }
    
    current_line = (char *)malloc( sizeof(char) * MAXLINE );
    current_column = 0;
    return 1;
}

void close_files(){
    fclose(src_file);
    src_file = NULL;

    fclose(listing_file);
    listing_file = NULL;
}

// GETTERS ------------------------------------------------------------------------------------
char get_next_source_char() {
    if( has_next_char(current_line, current_column) ){
        current_column++;
        return current_line[current_column];

    } else if( fgets(current_line, MAXLINE, src_file) ){
        current_line_number++;
        current_column = 0;

        // printChar(current_line_number, listing_file, NUMBER); 
        // printChar('.', listing_file, 0);
        // printChar(' ', listing_file, 0);

       // int printed = printChar( current_line[current_column], listing_file, 0);
        return current_line[current_column];   

    } else if ( feof(src_file) ){
       // printChar('\n', listing_file, 0);
        return EOF;
    } else {
        return 0;
    }
}

int get_current_line_num(){
    return current_line_number;
}

int get_current_column_num(){
    return current_column;
}

// PRINTERS ------------------------------------------------------------------------------------
void write_indicator(int column){
    for(int i = 0; i < column + 2; i++){
        print_char(' ', listing_file, CHAR);
    }
    print_char('^', listing_file, CHAR);
    print_char('\n', listing_file, CHAR);
}

void write_message(char *message){
    int i;
    for ( i = 0; i < strlen(message); i++){
        print_char(message[i], listing_file, CHAR);
    }
}

// HELPERS ------------------------------------------------------------------------------------ 
int print_char(char c, FILE *listing_file, int is_number){
    int printed_successfully = 0;
    
    if( listing_file ) {
        printed_successfully = fputc( c, listing_file );
    } else if (is_number) {
        printed_successfully = printf("%d", c);
    } else {
        printed_successfully = printf("%c", c);
    }
    
    return printed_successfully;
}

int has_next_char(char* current_line, int currentIndex){
    return current_line[currentIndex];
}
