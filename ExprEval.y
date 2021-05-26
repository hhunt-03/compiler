%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Semantics.h"
#include "IOMngr.h"
#include "SymTab.h"
#include "CodeGen.h"

extern  int  yylex();	    /* The next token function. */
extern  char *yytext;    /* The matched token text.  */
extern  int  yyleng;      /* The token text length.   */
extern  int  yyparse();
extern  int  yyerror(char *);
        void dumpTable();

extern sym_tab_t *table;
%}

%union {
  long val;
  char* string;
  struct expr_res_t* expr_res_t;
  struct instr_seq_t* instr_seq_t;
  struct b_expr_res_t* b_expr_res_t;
}

%type <string> Id

%type <instr_seq_t> StmtSeq
%type <instr_seq_t> Stmt
%type <instr_seq_t> IdSeq
%type <instr_seq_t> AssignStmt
%type <instr_seq_t> IfStmt
%type <instr_seq_t> IOStmt
%type <instr_seq_t> Loop
%type <instr_seq_t> FunctionDecl
%type <instr_seq_t> FunctionCall
%type <instr_seq_t> ReturnStmt
%type <instr_seq_t> ExprSeq
%type <instr_seq_t> ArraySeq

%type <expr_res_t> Factor
%type <expr_res_t> Item
%type <expr_res_t> Atom
%type <expr_res_t> Unit
%type <expr_res_t> Term
%type <expr_res_t> Expr
%type <expr_res_t> BExpr

%token <string> Ident 		
%token <string> IntLit 	
%token Int
%token Void
%token Return

%token IF
%token ELSE
%token WHILE
%token FOR

%token READ
%token PRINT
%token PRINTLINES
%token PRINTSPACES

// arithmetic operators
%token EQ	
%token LESS_THAN
%token GREATER_THAN
%token LESS_THAN_EQUALS_TO
%token GREATER_THAN_EQUALS_TO
%token NOT_EQUAL

// boolean operators
%token NOT
%token AND
%token OR

%%

Prog			    :	Declarations                                { finish(); } ;

Declarations  : Dec Declarations                            {};
Declarations	:										                      	  {};

Dec		        :	Int Ident '[' IntLit ']' ';'	              { char *size = to_int_type($4); enter_name(table, $2, ARRAY); set_current_attr(table, size); };
Dec		        :	Int Ident ';'	                              { enter_name(table, $2, VAR);};
Dec           : FunctionDecl                                {};

FunctionDecl  : Void Ident '(' ')' '{' Declarations StmtSeq '}'   { enter_name(table, $2, FUNCTION); set_current_attr(table, do_void_function_decl($2, $7));};
FunctionDecl  : Int Ident '(' ')' '{' Declarations StmtSeq '}'    { enter_name(table, $2, FUNCTION); set_current_attr(table, do_int_function_decl($2, $7));};

StmtSeq 	   	:	Stmt StmtSeq								                {$$ = append_seq($1, $2); };
StmtSeq	      :										                          {$$ = NULL;};

Stmt          : AssignStmt ';'                              {$$ = $1;}
Stmt          : IfStmt                                      {$$ = $1;};                        
Stmt          : IOStmt                                      {$$ = $1;};
Stmt          : Loop                                        {$$ = $1;}; 
Stmt          : FunctionCall                                {$$ = $1;};
Stmt          : ReturnStmt                                  {$$ = $1;};

AssignStmt		:	Id '=' Expr     							              {$$ = do_assign($1, $3);};
AssignStmt    : Id '[' Expr ']' '=' Expr                    {$$ = do_array_assign($1, $3, $6);};

IfStmt		    :	IF '(' BExpr ')' '{' StmtSeq '}'				   	{$$ = do_if($3, $6);};
IfStmt        : IF '(' BExpr ')' '{' StmtSeq '}'
                ELSE '{' StmtSeq '}'                        {$$ = do_if_else($3, $6, $10);};
        
IOStmt        : READ '(' IdSeq ')' ';'                      {$$ = $3; };
IOStmt        : READ '(' ArraySeq ')' ';'                   {$$ = $3; };
IOStmt		    :	PRINT '(' ExprSeq ')' ';'								    {$$ = $3; };
IOStmt        : PRINTLINES '(' Expr ')' ';'                 {$$ = do_printlines($3);}; 
IOStmt        : PRINTSPACES '(' Expr ')' ';'                {$$ = do_printspaces($3);}; 

Loop          : WHILE '(' BExpr ')' '{' StmtSeq '}'         {$$ = do_while($3, $6);};   
Loop          : FOR '(' AssignStmt ';' BExpr ';' AssignStmt ')'
                '{' StmtSeq '}'                             {$$ = do_for($3, $5, $7, $10);}

FunctionCall  : Id '(' ')' ';'                              {$$ = do_function_call($1);};

ReturnStmt    : Return Expr ';'                             {$$ = do_return_stmt($2);};

BExpr		      :	Expr EQ Expr							                  {$$ = do_eq($1, $3);} ;
BExpr		      :	Expr LESS_THAN Expr							            {$$ = do_less_than($1, $3);} ;
BExpr		      :	Expr GREATER_THAN Expr							        {$$ = do_greater_than($1, $3);} ;
BExpr		      :	Expr LESS_THAN_EQUALS_TO Expr							  {$$ = do_less_than_equals_to($1, $3);} ;
BExpr		      :	Expr GREATER_THAN_EQUALS_TO Expr					  {$$ = do_greater_than_equals_to($1, $3);} ;
BExpr		      :	Expr NOT_EQUAL Expr					                {$$ = do_not_equal($1, $3);} ;
BExpr         : NOT Expr                                    {$$ = do_not($2); };
BExpr         : Expr AND Expr                               {$$ = do_and($1, $3); };      
BExpr         : Expr OR Expr                                {$$ = do_or($1, $3); };  
BExpr         : Expr                                        {$$ = $1;} 

ExprSeq       : ExprSeq ',' Expr                            {$$ = append_seq($1, do_print($3)); };
ExprSeq       : Expr                                        {$$ = do_print($1); };

Expr          : '[' BExpr ']'                               {$$ = $2; };
Expr	    		:	Expr '+' Term						                		{$$ = do_add($1, $3); };
Expr	    		:	Expr '-' Term						                		{$$ = do_subtraction($1, $3); }; 
Expr	    		:	Term								                      	{$$ = $1; } ;

Term	      	:	Term '*' Factor						              		{$$ = do_mult($1, $3); };
Term	      	:	Term '/' Factor						              		{$$ = do_division($1, $3); };
Term	      	:	Term '%' Factor						              		{$$ = do_mod($1, $3); };
Term          : '-' '(' Expr ')'                            {$$ = do_unary_minus($3); };
Term	      	:	Unit  									                    {$$ = $1; };

Unit          : Unit '^' Factor                             {$$ = do_exponent($1, $3); };
Unit          : Factor                                      {$$ = $1; };

Factor        : Id '[' Expr ']'                             {$$ = do_array_access($1, $3); };
Factor        : '(' Expr ')'                                {$$ = $2; };
Factor        : Item                                        {$$ = $1; };

Item          : Id '(' ')'                                  {$$ = do_int_function_call($1);};
Item          : Atom                                        {$$ = $1;};

Atom	        :	IntLit								                    	{$$ = do_int_lit(yytext); };
Atom	  	    :	Ident									                      {$$ = do_rval($1); };

IdSeq         : IdSeq ',' Id                                {$$ = append_seq($1, do_read($3)); };
IdSeq         : Id                                          {$$ = do_read($1); };

ArraySeq      : ArraySeq ',' Id '[' Expr ']'                {$$ = append_seq($1, do_array_read($3, $5));};
ArraySeq      : Id '[' Expr ']'                             {$$ = do_array_read($1, $3);};

Id			      : Ident								                      	{$$ = $1;}
 
%%

int yyerror(char *s)  {
  printf("yyerror : %s\n", s);
  write_indicator(get_current_column_num());
  write_message("Illegal Character in YACC\n");
  return 1;
}
