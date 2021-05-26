#include <stdio.h>
#include "SymTab.h"
#include "IOMngr.h"

extern int yyparse();

sym_tab_t *table;
FILE *file;

int main(int argc, char * argv[]) {
	table = create_sym_tab(33);
	open_files(argv[1], argv[2]);
	if (argc == 4) {
		file = fopen(argv[3], "w");
	} else {
		file = stdout;
	}

	yyparse();
}

