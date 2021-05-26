#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "CodeGen.h"

#define MAXREG 10

extern FILE *file;

static int next_label = 1;
static char buf[16];


struct tmp_reg {
  unsigned char free;
  unsigned char used;
  char *name;
} registers[10] 
    = { {1, 0, "$t0"},  {1, 0, "$t1"},  {1, 0, "$t2"},  {1, 0, "$t3"},  
        {1, 0, "$t4"},  {1, 0, "$t5"},  {1, 0, "$t6"},  {1, 0, "$t7"},  
        {1, 0, "$t8"},  {1, 0, "$t9"}};


static char *copy_str(char *str) {
  return (str) ? strdup(str) : NULL;
}

instr_seq_t * gen_instr(char *label, char *opcode, char *oprnd1, char *oprnd2, char *oprnd3){
  instr_seq_t *instr;
  
  instr = (instr_seq_t *)malloc(sizeof(instr_seq_t));
  instr->label  = copy_str(label);
  instr->opcode = copy_str(opcode);
  instr->oprnd1 = copy_str(oprnd1);
  instr->oprnd2 = copy_str(oprnd2);
  instr->oprnd3 = copy_str(oprnd3);
  instr->next = NULL;
	
  return instr;
}
	
extern instr_seq_t *append_seq (instr_seq_t *seq1, instr_seq_t *seq2){ 
  instr_seq_t *instr;

  if (!seq1) {
    return seq2;
  } else {
    instr = seq1;
    while (instr->next) {
      instr = instr->next;
    }

    instr->next = seq2;
    
    return seq1;
  }
}

void write_seq(instr_seq_t *seq) {
  instr_seq_t *instr;

  instr = seq;
  while (instr) {
    if (instr->label){
       fprintf(file, "%s:", instr->label);
    }
    if (instr->opcode) {
			fprintf(file,"\t%s\t",instr->opcode);
    }
    if (instr->oprnd1){
      fprintf(file,"\t%s",instr->oprnd1);
    }
    if (instr->oprnd2){
      fprintf(file,", %s",instr->oprnd2);
    }
    if (instr->oprnd3){ 
      fprintf(file,", %s",instr->oprnd3);
    }
  }
  
  fprintf(file,"\n");
  instr = instr->next;

  if (file != stdout) {
    fclose(file);
  }
}

char *gen_label() {
   char *label;

  label = (char *)malloc(8);
  sprintf(label,"L%d", next_label++);
  
  return label;
}
	 
int avail_tmp_reg(){	
  int i;

  for (i = 0; i < MAXREG; i++) {
    if (registers[i].free) {
      registers[i].free = 0;
      registers[i].used = 1;
      return i;
    }
  }
  
  return -1;
}

char *tmp_reg_name (int reg_num){
  if ((reg_num >= 0) && ( reg_num < MAXREG)) {
    return registers[reg_num].name;
  } else if (reg_num == RETURN_REG){
    return strdup("$v0");
  } else {
    return NULL;
  }
}

void release_tmp_reg(int num){
  if ((num >= 0) && ( num < MAXREG)) {
    registers[num].free = 1;
  } 
  return;
}

void reset_all_tmp_reg(){ 
  int i;

  for (i = 0; i < MAXREG; i++) {
    registers[i].free = 1;
    registers[i].used = 0;
  }

  return;
}

instr_seq_t * save_seq(){
  instr_seq_t *save = NULL;
  instr_seq_t *code = NULL;

  int i, scnt;
  char addr[8], offset[8];
  
  scnt = 0;
  save = NULL;
  for (i = 0; i < MAXREG; i++) {
    if (!registers[i].free) {
      scnt++;
      sprintf(addr, "%d($sp)", scnt*4);
      save = append_seq(save, gen_instr(NULL, "sw", tmp_reg_name(i), addr, NULL));
    }
  }
  if (scnt > 0) {
    sprintf(offset,"%d",scnt*4);
    code = gen_instr(NULL, "subu", "$sp", "$sp", offset);
    append_seq(code, save);
  }
  
  return code;
}

instr_seq_t *restore_seq(){ 
  instr_seq_t *code = NULL;
  instr_seq_t *save = NULL;
  int i, scnt;

  char addr[8], offset[8];
  
  scnt = 0;
  save = NULL;
  for (i = 0; i < MAXREG; i++) {
    if (!registers[i].free) {
      scnt++;
      sprintf(addr, "%d($sp)", scnt*4);
      save = append_seq(save, gen_instr(NULL, "lw", tmp_reg_name(i), addr, NULL));
    }
  }
  if (scnt > 0) {
    sprintf(offset, "%d", scnt*4);
    code = append_seq(save, gen_instr(NULL, "addu", "$sp", "$sp", offset));
  }
  
  return code;
}

char *imm(int val){
  sprintf( buf, "%d", val);
  return buf;
}

char *reg_off(int offset, char *reg){
  sprintf( buf,"%d(%s)", offset, reg);
  return buf;
}


