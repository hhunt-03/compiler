#ifndef _SEMANTICS_IS_INCLUDED_
#define _SEMANTICS_IS_INCLUDED_

#include "CodeGen.h"

/* Semantic Records */
typedef struct {
  struct sym_entry_t * the_entry;
  struct id_list_t * next;
} id_list_t;

typedef struct expr_res_t {
  int reg;
  instr_seq_t * instrs;
} expr_res_t;

typedef struct expr_res_list_t {
	expr_res_t *expr;
	struct expr_res_list_t *next;
} expr_res_list_t;

typedef struct b_expr_res_t{
  char * label;
  instr_seq_t *instrs;
} b_expr_res_t;


/* Semantics Actions */
extern  expr_res_t   * do_int_lit(char *digits);
extern  expr_res_t   * do_rval(char *name);
extern  instr_seq_t  * do_assign(char *name, expr_res_t *res1);

// arithmetic operators ---------------------------------------------------------------------------------------
extern  expr_res_t   * do_add(expr_res_t *res1,   expr_res_t *res2);
extern  expr_res_t   * do_subtraction( expr_res_t *res1,  expr_res_t *res2);
extern  expr_res_t   * do_mult(expr_res_t *res1,   expr_res_t *res2);
extern  expr_res_t   * do_division(expr_res_t *res1,  expr_res_t *res2); 

extern  expr_res_t   * do_mod(expr_res_t *res1,  expr_res_t *res2); 
extern  expr_res_t   * do_exponent(expr_res_t *res1,  expr_res_t *res2); 
extern  expr_res_t   * do_unary_minus(expr_res_t *res1 );

// relational operators ---------------------------------------------------------------------------------------
extern  expr_res_t   * do_eq( expr_res_t *res1,  expr_res_t* res2); 
extern  expr_res_t   * do_less_than( expr_res_t *res1,  expr_res_t* res2); 
extern  expr_res_t   * do_greater_than( expr_res_t *res1,  expr_res_t* res2); 
extern  expr_res_t   * do_less_than_equals_to( expr_res_t *res1,  expr_res_t * res2); 
extern  expr_res_t   * do_greater_than_equals_to( expr_res_t *res1,  expr_res_t *res2); 
extern  expr_res_t   * do_not_equal( expr_res_t *res1,  expr_res_t *res2); 

// boolean operators ---------------------------------------------------------------------------------------
extern  expr_res_t   * do_not( expr_res_t * res1); 
extern  expr_res_t   * do_and( expr_res_t * res1,  expr_res_t * res2);
extern  expr_res_t   * do_or( expr_res_t * res1,  expr_res_t * res2); 

// integer i/o ------------------------------------------------------------------------------------------------
extern  instr_seq_t * do_print( expr_res_t *expr);
extern  instr_seq_t * do_read(char *var);
extern  instr_seq_t * do_array_read(char *name,  expr_res_t *res);
extern  instr_seq_t * do_printlines( expr_res_t *res1);
extern  instr_seq_t * do_printspaces( expr_res_t *res1); 

// control stuctures -------------------------------------------------------------------------------------------
extern  instr_seq_t  * do_if( expr_res_t *res,  instr_seq_t *seq);
extern  instr_seq_t  * do_if_else( expr_res_t *res,  instr_seq_t *if_seq,  instr_seq_t *else_seq); //added in v3.1
extern  instr_seq_t  * do_while( expr_res_t *res,  instr_seq_t *seq);
extern  instr_seq_t  * do_for( instr_seq_t *init, 
                                 expr_res_t *condition, 
                                 instr_seq_t *incrementer, 
                                 instr_seq_t *body); 
// arrays ----------------------------------------------------------------------------------
extern  instr_seq_t * do_array_assign(char* name,  expr_res_t* index,  expr_res_t* value);
extern  expr_res_t  * do_array_access(char* name,  expr_res_t* index);

// functions ----------------------------------------------------------------------------------
extern  instr_seq_t * do_void_function_decl(char* name,  instr_seq_t* seq);
extern  instr_seq_t * do_int_function_decl(char* name,  instr_seq_t* seq);
extern  instr_seq_t * do_function_call(char* name);
extern  instr_seq_t * do_return_stmt(expr_res_t* res);

extern  expr_res_t * do_int_function_call(char* name);

// others ---------------------------------------------------------------------------------------
extern  b_expr_res_t  * do_b_expr (expr_res_t *res1, expr_res_t *res2);
extern void	finish();

char* to_int_type(char* intlit);

#endif