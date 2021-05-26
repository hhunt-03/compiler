#ifndef IOMNGR_IS_INCLUDED
#define IOMNGR_IS_INCLUDED

#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 1024
#define CHAR    0
#define NUMBER  1

int     open_files(char *source_file_name, char *listing_file_name);
void    close_files();

char    get_next_source_char();
int     get_current_line_num();
int     get_current_column_num();

void    write_indicator(int column);
void    write_message(char * message);

#endif