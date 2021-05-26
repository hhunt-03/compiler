/* Semantics.c
   Support and semantic action routines.
*/

#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "CodeGen.h"
#include "Semantics.h"
#include "SymTab.h"
#include "IOMngr.h"

extern sym_tab_t *table;

/* Semantics support routines */
expr_res_t* do_int_lit(char *digits) {
  expr_res_t *res;
  
  res = (expr_res_t *)malloc(sizeof(expr_res_t));
  res->reg = avail_tmp_reg();
  res->instrs = gen_instr( NULL, "li", tmp_reg_name(res->reg), digits, NULL);

  return res;
}

expr_res_t * do_rval(char *name)  { 
  expr_res_t *res;
  
  if (!find_name(table, name)) {
		write_indicator(get_current_column_num());
		write_message("Undeclared variable\n");
  }

  res = (expr_res_t *) malloc(sizeof(expr_res_t));
  res->reg = avail_tmp_reg();
  res->instrs = gen_instr(NULL, "lw", tmp_reg_name(res->reg), name, NULL);

  return res;
}

// ARTITHMETIC OPS ==============================================================
// ADDITION
expr_res_t *do_add(expr_res_t * res1, expr_res_t *res2)  { 
  int reg;
   
  reg = avail_tmp_reg();
  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr(NULL,"add", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));
  
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);
  
  res1->reg = reg;
  
  free(res2);
  
  return res1;
}

// Added in v1.1
// SUBTRACTION
expr_res_t* do_subtraction ( expr_res_t *res1, expr_res_t* res2 ){ 
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "sub", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));
  
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  res1->reg = reg;
  free(res2); 
   
  return res1;
}

// Added in v1.2
// UNARY MINUS - just loads -1 and calls doMult
expr_res_t* do_unary_minus( expr_res_t *res1 ){ 
  expr_res_t* res2 = (expr_res_t *)malloc(sizeof(expr_res_t));

  res2->reg  = avail_tmp_reg();
  res2->instrs = gen_instr( NULL, "addi", tmp_reg_name(res2->reg), "$0", "-1");

  return do_mult(res1, res2);  
}

// MULTIPLICATION
expr_res_t * do_mult(expr_res_t * res1, expr_res_t * res2)  { 
  int reg;
   
  reg = avail_tmp_reg();
  append_seq(res1->instrs,res2->instrs);
  append_seq(res1->instrs,gen_instr(NULL,"mul", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));
  
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  res1->reg = reg;

  free(res2);
  return res1;
}

// Added in v1.1
// DIVISIION
expr_res_t* do_division ( expr_res_t *res1, expr_res_t* res2 ){ 
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "div", tmp_reg_name(res1->reg), tmp_reg_name(res2->reg), NULL));
  append_seq(res1->instrs, gen_instr( NULL, "mflo", tmp_reg_name(reg), NULL, NULL));

  
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);
  
  res1->reg = reg;
  free(res2);

  return res1;
}

// Added in v1.1
// MODULUS
expr_res_t* do_mod ( expr_res_t *res1, expr_res_t* res2 ){ 
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "div", tmp_reg_name(res1->reg), tmp_reg_name(res2->reg), NULL));
  append_seq(res1->instrs, gen_instr( NULL, "mfhi", tmp_reg_name(reg), NULL, NULL));
  
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  res1->reg = reg;
  free(res2); 
   
  return res1;
}

//Added in v1.2
// EXPONENTIATION
expr_res_t* do_exponent ( expr_res_t *res1, expr_res_t* res2 ){ 
  int i = avail_tmp_reg();
  int reg = avail_tmp_reg();
  int canLoop = avail_tmp_reg();
  
  append_seq(res1->instrs, res2->instrs);

  instr_seq_t* init = gen_instr( NULL, "addi", tmp_reg_name(i), "$zero", "0");

  expr_res_t* condition = (expr_res_t*)malloc(sizeof(expr_res_t));
  condition->instrs = gen_instr( NULL, "slt", tmp_reg_name(canLoop), tmp_reg_name(i), tmp_reg_name(res2->reg));
  condition->reg = canLoop;

  append_seq(res1->instrs, do_for(init, 
                               condition, 
                               gen_instr( NULL, "addi", tmp_reg_name(i), tmp_reg_name(i), "1"),
                               gen_instr(NULL, "mul", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res1->reg))));

  release_tmp_reg(i);
  release_tmp_reg(canLoop);
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  res1->reg = reg;
  free(res2);

  return res1;
}

// RELATIONAL OPERATORS
// Added in v1.2
extern expr_res_t * do_eq(expr_res_t * res1, expr_res_t * res2) {
  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "seq", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res;
}

//Added in v1.2
extern expr_res_t * do_less_than(expr_res_t * res1, expr_res_t * res2) {
//  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "slt", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  //Res->reg = reg;;
  //Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  res1->reg = reg;

//  free(res1);
  free(res2);

  return res1;
}

//Added in v1.2
extern expr_res_t * do_greater_than(expr_res_t * res1, expr_res_t * res2) {
  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "sgt", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res;
}

//Added in v1.2
extern expr_res_t * do_less_than_equals_to(expr_res_t * res1, expr_res_t * res2) {
  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "sle", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res;
}

//Added in v1.2
extern expr_res_t * do_greater_than_equals_to(expr_res_t * res1, expr_res_t * res2) {
  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "sge", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res;
} 

extern expr_res_t * do_not_equal(expr_res_t * res1, expr_res_t * res2){
  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "sne", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res;
}

// BOOLEAN OPERATORS --------------------------------------------------------------------------
// NOT       
// added in v1.2
extern expr_res_t   * do_not(expr_res_t * res1){
 expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, gen_instr( NULL, "not", tmp_reg_name(reg), tmp_reg_name(res1->reg), NULL));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);

  free(res1);

  return Res; 
}

// AND   
// added in v1.2
extern expr_res_t   * do_and(expr_res_t * res1, expr_res_t * res2){
  expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "and", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res; 
}

// OR       
// added in v1.2
extern expr_res_t   * do_or(expr_res_t * res1, expr_res_t * res2){
expr_res_t * Res = (expr_res_t *) malloc(sizeof(expr_res_t));
  int reg = avail_tmp_reg();

  append_seq(res1->instrs, res2->instrs);
  append_seq(res1->instrs, gen_instr( NULL, "or", tmp_reg_name(reg), tmp_reg_name(res1->reg), tmp_reg_name(res2->reg)));

  Res->reg = reg;
  Res->instrs = res1->instrs;

  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);

  free(res1);
  free(res2);

  return Res; 
}

// INTEGER I/O ---------------------------------------------------------------------------------

// READ 
// added in v2.1
extern instr_seq_t * do_read(char * var){
  if (!find_name(table, var)) {
    write_indicator(get_current_column_num());
    write_message("Undeclared variable");
  }

  instr_seq_t* code = (instr_seq_t*)malloc(sizeof(instr_seq_t)); 

  append_seq(code, gen_instr( NULL, "li", "$v0", "5", NULL));
  append_seq(code, gen_instr( NULL, "syscall", NULL, NULL, NULL));
  append_seq(code, gen_instr( NULL, "sw", "$v0", var, NULL));

  free(var);
  var = NULL;
  
  return code;
}

extern instr_seq_t* do_array_read(char* name, expr_res_t* res){
 instr_seq_t *code = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  
  if (!find_name(table, name)) {
		write_indicator(get_current_column_num());
		write_message("ERROR : Undeclared Variable\n");
  }

  append_seq(code, res->instrs);

  int index = res->reg;
  int arrayreg = avail_tmp_reg();
  int var = avail_tmp_reg();

  char* finalreg = (char*)malloc(sizeof(char)*20);
  char* close = (char*)malloc(sizeof(char)*2);

  strcpy(finalreg, "0(");
  strcpy(close, ")");

  strcat(finalreg, tmp_reg_name(arrayreg));
  strcat(finalreg, close);

  append_seq(code, gen_instr( NULL, "li", "$v0", "5", NULL));
  append_seq(code, gen_instr( NULL, "syscall", NULL, NULL, NULL));
  append_seq(code, gen_instr( NULL, "move", tmp_reg_name(var), "$v0", NULL));

  append_seq(code, gen_instr(NULL, "la", tmp_reg_name(arrayreg), name, NULL)); //loading base array address
  append_seq(code, gen_instr(NULL, "mul", tmp_reg_name(index), tmp_reg_name(index), "4")); // getting offset
  append_seq(code, gen_instr(NULL, "add", tmp_reg_name(arrayreg), tmp_reg_name(index), tmp_reg_name(arrayreg))); // adding offset to the base
  append_seq(code, gen_instr(NULL, "sw", tmp_reg_name(var), finalreg, NULL)); // storing value into the array

  release_tmp_reg(index);
  release_tmp_reg(arrayreg);
  release_tmp_reg(var);

  free(res);

  return code;
}

// extern instr_seq_t* doArrayRead(char* name, char* i){
//  instr_seq_t *code = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  
//   if (!findName(table, name)) {
// 		writeIndicator(get_current_column_num());
// 		writeMessage("ERROR : Undeclared Variable\n");
//   }

//   int index = avail_tmp_reg();
//   int arrayreg = avail_tmp_reg();
//   int var = avail_tmp_reg();

//   char* finalreg = (char*)malloc(sizeof(char)*20);
//   char* close = (char*)malloc(sizeof(char)*2);

//   strcpy(finalreg, "0(");
//   strcpy(close, ")");

//   strcat(finalreg, tmp_reg_name(arrayreg));
//   strcat(finalreg, close);

//   append_seq(code, gen_instr( NULL, "li", "$v0", "5", NULL));
//   append_seq(code, gen_instr( NULL, "syscall", NULL, NULL, NULL));
//   append_seq(code, gen_instr( NULL, "move", tmp_reg_name(var), "$v0", NULL));

//   append_seq(code, gen_instr(NULL, "la", tmp_reg_name(arrayreg), name, NULL)); //loading base array address
//   append_seq(code, gen_instr(NULL, "addi", tmp_reg_name(index), tmp_reg_name(index), i));
//   append_seq(code, gen_instr(NULL, "mul", tmp_reg_name(index), tmp_reg_name(index), "4")); // getting offset
//   append_seq(code, gen_instr(NULL, "add", tmp_reg_name(arrayreg), tmp_reg_name(index), tmp_reg_name(arrayreg))); // adding offset to the base
//   append_seq(code, gen_instr(NULL, "sw", tmp_reg_name(var), finalreg, NULL)); // storing value into the array

//   release_tmp_reg(index);
//   release_tmp_reg(arrayreg);
//   release_tmp_reg(var);

//   return code;
// }


// PRINTERS =============================================================================
instr_seq_t * do_print(expr_res_t * Expr) { 
  instr_seq_t *code;
  code = Expr->instrs;
  
  append_seq(code,gen_instr(NULL,"li","$v0","1",NULL));
  append_seq(code,gen_instr(NULL,"move","$a0",tmp_reg_name(Expr->reg),NULL));
  append_seq(code,gen_instr(NULL,"syscall",NULL,NULL,NULL));

  release_tmp_reg(Expr->reg);
  free(Expr);

  return code;
}

extern instr_seq_t * do_printlines(expr_res_t* res1){
  expr_res_t* condition = (expr_res_t*)malloc(sizeof(expr_res_t));
  condition->reg = avail_tmp_reg();
  condition->instrs = gen_instr(NULL, "sgt", tmp_reg_name(condition->reg), tmp_reg_name(res1->reg), "$zero");

  instr_seq_t* body = gen_instr(NULL, "addi", "$a0", "$0", "0xA");
  append_seq(body, gen_instr(NULL, "addi", "$v0", "$0", "11"));
  append_seq(body, gen_instr(NULL,"syscall",NULL,NULL,NULL));
  
  return do_for( res1->instrs, 
                condition, 
                gen_instr(NULL, "addi", tmp_reg_name(res1->reg), tmp_reg_name(res1->reg), "-1"),
                body);
}

extern instr_seq_t * do_printspaces(expr_res_t* res1){
  expr_res_t* condition = (expr_res_t*)malloc(sizeof(expr_res_t));
  condition->reg = avail_tmp_reg();
  condition->instrs = gen_instr(NULL, "sgt", tmp_reg_name(condition->reg), tmp_reg_name(res1->reg), "$zero");

  instr_seq_t* body = gen_instr(NULL, "addi", "$a0", "$0", "32");
  append_seq(body, gen_instr(NULL, "addi", "$v0", "$0", "11"));
  append_seq(body, gen_instr(NULL,"syscall",NULL,NULL,NULL));
  
  return do_for( res1->instrs, 
                condition, 
                gen_instr(NULL, "addi", tmp_reg_name(res1->reg), tmp_reg_name(res1->reg), "-1"),
                body);
}

// ------------------------------------------------------------------------

instr_seq_t * do_assign(char *name, expr_res_t * Expr) { 
  instr_seq_t *code = (instr_seq_t*)malloc(sizeof(instr_seq_t));  

   if (!find_name(table, name)) {
		write_indicator(get_current_column_num());
		write_message("ERROR : Undeclared Variable\n");
   }

  append_seq(code, Expr->instrs);
  append_seq(code, gen_instr(NULL,"sw", tmp_reg_name(Expr->reg), name, NULL));

  if( Expr->reg > 0 ){
    release_tmp_reg(Expr->reg);
  }
  free(Expr);
  
  return code;
}

// BINARY EVALUATINIONS ==================================================================
extern b_expr_res_t * do_b_expr(expr_res_t * res1,  expr_res_t * res2) {
	b_expr_res_t * bRes;
 	bRes = (b_expr_res_t *) malloc(sizeof(b_expr_res_t));
	bRes->label = gen_label();

	append_seq(res1->instrs, res2->instrs);
	append_seq(res1->instrs, gen_instr( NULL, 
                                   "bne", 
                                   tmp_reg_name(res1->reg), 
                                   tmp_reg_name(res2->reg), 
                                   bRes->label));
	
  bRes->instrs = res1->instrs;
	
  release_tmp_reg(res1->reg);
  release_tmp_reg(res2->reg);
	
  free(res1);
	free(res2);
	
  return bRes;
}

extern instr_seq_t * do_if(expr_res_t * Res, instr_seq_t * seq) {
  char * label = gen_label();

  append_seq(Res->instrs, gen_instr(NULL, "beq", "$zero", tmp_reg_name(Res->reg), label));
  instr_seq_t * seq2 = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  seq2 = append_seq(Res->instrs, seq);
  append_seq(seq2, gen_instr(label, NULL, NULL, NULL, NULL));

  free(Res);
  return seq2;
}

extern instr_seq_t * do_if_else(expr_res_t * Res, instr_seq_t * ifSeq, instr_seq_t* elseSeq) {
  char * elseLabel  = gen_label();
  char * endLabel   = gen_label();

  // conditional
  append_seq(Res->instrs, gen_instr(NULL, "beq", "$zero", tmp_reg_name(Res->reg), elseLabel));
  // if sequence
  append_seq(Res->instrs, ifSeq);
  append_seq(Res->instrs, gen_instr(NULL, "j", endLabel, NULL, NULL));
  // else 
  append_seq(Res->instrs, gen_instr(elseLabel, NULL, NULL, NULL, NULL));
  // else sequence
  append_seq(Res->instrs, elseSeq);
  // end
  append_seq(Res->instrs, gen_instr(endLabel, NULL, NULL, NULL, NULL));

  instr_seq_t * seq = (instr_seq_t*)malloc(sizeof(instr_seq_t)); 
  seq = Res->instrs;

  free(Res);
  return seq;
}

extern instr_seq_t  * do_while(expr_res_t * Res, instr_seq_t * seq){
  char * startLabel = gen_label();
  char * endLabel   = gen_label();

  instr_seq_t* seq2 = gen_instr(startLabel, NULL, NULL, NULL, NULL);

  append_seq(seq2, Res->instrs);
  
  append_seq(seq2, gen_instr(NULL, "beq", "$zero", tmp_reg_name(Res->reg), endLabel));

  append_seq(seq2, seq);
  append_seq(seq2, gen_instr(NULL, "j", startLabel, NULL, NULL));
  append_seq(seq2, gen_instr(endLabel, NULL, NULL, NULL, NULL));

  release_tmp_reg(Res->reg);
  return seq2; 
}

extern instr_seq_t  * do_for(instr_seq_t * init, expr_res_t * condition, 
                                instr_seq_t * incrementer, instr_seq_t* body){  
  instr_seq_t* seq = init;
  append_seq(seq, do_while(condition, append_seq(body, incrementer)));

  return seq;
}

// ARRAYS --------------------------------------------------------------
extern instr_seq_t * do_array_assign(char* name, expr_res_t* index, expr_res_t* value){
  instr_seq_t *code = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  
  if (!find_name(table, name)) {
		write_indicator(get_current_column_num());
		write_message("ERROR : Undeclared Variable\n");
  }

  code = index->instrs;
  append_seq(code, value->instrs);

  int arrayreg = avail_tmp_reg();
  char* finalreg = (char*)malloc(sizeof(char) * (strlen(tmp_reg_name(index->reg))+3));
  char* close = (char*)malloc(sizeof(char)*2);

  strcpy(finalreg, "0(");
  strcpy(close, ")");

  strcat(finalreg, tmp_reg_name(arrayreg));
  strcat(finalreg, close);

  append_seq(code, gen_instr(NULL, "la", tmp_reg_name(arrayreg), name, NULL)); //loading base array address
  //append_seq(code, gen_instr(NULL, "sll", tmp_reg_name(index->reg), tmp_reg_name(index->reg), "2")); // getting offset
  append_seq(code, gen_instr(NULL, "mul", tmp_reg_name(index->reg), tmp_reg_name(index->reg), "4")); // getting offset
  append_seq(code, gen_instr(NULL, "add", tmp_reg_name(arrayreg), tmp_reg_name(index->reg), tmp_reg_name(arrayreg))); // adding offset to the base
  append_seq(code, gen_instr(NULL, "sw", tmp_reg_name(value->reg), finalreg, NULL)); // storing value into the array
  
  free(finalreg);
  free(close);

  release_tmp_reg(index->reg);
  release_tmp_reg(value->reg);
  release_tmp_reg(arrayreg);

  free(index);
  free(value);
  
  return code;
}

extern expr_res_t * do_array_access(char* name, expr_res_t* index){
  expr_res_t* seq = (expr_res_t*)malloc(sizeof(expr_res_t));

  int arrayreg = avail_tmp_reg();
  
  char* finalreg = (char*)malloc(sizeof(char) * strlen(tmp_reg_name(index->reg)+3));
  char* close = (char*)malloc(sizeof(char)*2);

  strcpy(finalreg, "0(");
  strcpy(close, ")");
  strcat(finalreg, tmp_reg_name(arrayreg));
  strcat(finalreg, close);

  seq->instrs = index->instrs;
  seq->reg = arrayreg;

  append_seq(seq->instrs, gen_instr(NULL, "la", tmp_reg_name(arrayreg), name, NULL));
  append_seq(seq->instrs, gen_instr(NULL, "sll", tmp_reg_name(index->reg), tmp_reg_name(index->reg), "2"));
  append_seq(seq->instrs, gen_instr(NULL, "add", tmp_reg_name(arrayreg), tmp_reg_name(arrayreg), tmp_reg_name(index->reg)));
  append_seq(seq->instrs, gen_instr(NULL, "lw", tmp_reg_name(arrayreg), finalreg, NULL));

  release_tmp_reg(index->reg);
  free(index);

  return seq;
}

// FUNCTIONS -------------------------------------------------------------------------
extern instr_seq_t * do_void_function_decl(char* name, instr_seq_t* seq){
  instr_seq_t* code = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  code = gen_instr(name, NULL, NULL, NULL, NULL);
  append_seq(code, gen_instr(NULL, "addi", "$sp", "$sp", "-8")); //activation record
  append_seq(code, gen_instr(NULL, "sw", "$ra", "0($sp)", NULL)); // storing return address
  if(seq) { append_seq(code, seq); }
  append_seq(code, gen_instr(NULL, "lw", "$ra", "0($sp)", NULL)); // loading return address
  append_seq(code, gen_instr(NULL, "addi", "$sp", "$sp", "8")); // popping off stack
  append_seq(code, gen_instr(NULL, "jr", "$ra", NULL, NULL)); // loading return address

  free(seq);

  return code;

}

extern instr_seq_t * do_int_function_decl(char* name, instr_seq_t* seq){
  instr_seq_t* code = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  
  code = gen_instr(name, NULL, NULL, NULL, NULL);

  if( strcmp(name, "main") == 0 ){
    append_seq(code, seq);

    append_seq(code, gen_instr(NULL, "li", "$v0", "10", NULL)); 
    append_seq(code, gen_instr(NULL,"syscall",NULL,NULL,NULL));
  } else {
   append_seq(code, gen_instr(NULL, "addi", "$sp", "$sp", "-8")); //activation record
   append_seq(code, gen_instr(NULL, "sw", "$ra", "0($sp)", NULL)); // storing return address
    if(seq) { append_seq(code, seq); }
   append_seq(code, gen_instr(NULL, "lw", "$ra", "0($sp)", NULL)); // loading return address
   append_seq(code, gen_instr(NULL, "addi", "$sp", "$sp", "8")); // popping off stack
   append_seq(code, gen_instr(NULL, "jr", "$ra", NULL, NULL)); // loading return address
  }

  return code;
}

extern instr_seq_t * do_function_call(char* name){
  instr_seq_t* seq = (instr_seq_t*)malloc(sizeof(instr_seq_t));

  append_seq(seq, save_seq());
  append_seq(seq, gen_instr(NULL, "jal", name, NULL, NULL));
  append_seq(seq, restore_seq());

  return seq;
}

extern instr_seq_t * do_return_stmt(expr_res_t* res){
  instr_seq_t* seq = (instr_seq_t*)malloc(sizeof(instr_seq_t));
  seq = res->instrs;

  append_seq(seq, gen_instr(NULL, "addi", "$v0", tmp_reg_name(res->reg), "0"));
  
  release_tmp_reg(res->reg);
  
  return seq;
}

extern expr_res_t * do_int_function_call(char* name){
  expr_res_t* res = (expr_res_t*)malloc(sizeof(expr_res_t));
  res->reg = RETURN_REG;

  res->instrs = save_seq();
  if( !res->instrs ){
    res->instrs = gen_instr(NULL, "jal", name, NULL, NULL);
  } else {
    append_seq(res->instrs, gen_instr(NULL, "jal", name, NULL, NULL));
  }
  append_seq(res->instrs, restore_seq());

  return res;
}

// FINISH ==========================================================================================
void finish() {
  instr_seq_t* code = (instr_seq_t*)malloc(sizeof(instr_seq_t));

  //code = gen_instr(NULL, ".text", NULL, NULL, NULL);
  
  if( find_name(table, "main") ){
    append_seq(code, (instr_seq_t*)table->current->attribute);
  }

  int has_more = start_iterator(table);
  while ( has_more ){
    if (table->current->attribute->type == FUNCTION && strcmp(table->current->name, "main")  ) {
        append_seq(code, (instr_seq_t*)table->current->attribute );
    }
    has_more = next_entry(table);
  }

  append_seq(code, gen_instr(NULL, NULL, NULL, NULL, NULL));
  append_seq(code, gen_instr(NULL,".data",NULL,NULL, NULL));
  append_seq(code, gen_instr(NULL,".align","4",NULL, NULL));
  
  has_more = start_iterator(table);
  while ( has_more ) {

    if( table->current->attribute->type == ARRAY ){
      append_seq(code, gen_instr((char *) get_current_name(table), ".space", (char*)table->current->attribute, NULL, NULL));
    } else if (table->current->attribute->type == VAR ) {
      append_seq(code, gen_instr((char *) get_current_name(table), ".word", "0", NULL, NULL));
    }
    
    has_more = next_entry(table);
  }
  
  append_seq(code, gen_instr("_nl",".asciiz","\"\\n\"",NULL,NULL));
  write_seq(code);
  
  return;
}

char* to_int_type(char* intlit){
  int result =  4 * atoi(intlit);
  char *buffer = (char*)malloc( sizeof(char) * 20);
  sprintf(buffer, "%d", result);
  return buffer;
}

