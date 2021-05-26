#ifndef _CODEGEN_IS_INCLUDED_
#define _CODEGEN_IS_INCLUDED_

#include <stdio.h>

#define RETURN_REG -1

extern FILE *assm_file;

typedef struct instr_seq_t {
  char *label;
  char *opcode;
  char *oprnd1;
  char *oprnd2;
  char *oprnd3;
  struct instr_seq_t *next;
} instr_seq_t;

extern void				    init_code_gen(char *filename);

extern instr_seq_t*   gen_instr(char *label, char *opcode, 
                                     char *oprnd1, char *oprnd2, char *oprnd3);
extern char*					gen_label();

extern instr_seq_t*   append_seq( instr_seq_t *seq1, instr_seq_t *seq2);
extern void 				  write_seq( instr_seq_t *seq);

extern int  					avail_tmp_reg();
extern char*				  tmp_reg_name(int reg_num);
extern void						release_tmp_reg(int num);
extern void 	        reset_all_tmp_reg();

extern instr_seq_t*   save_seq();
extern instr_seq_t*   restore_seq();

extern char*					imm(int val);
extern char*					reg_off(int offset, char *reg);

#endif