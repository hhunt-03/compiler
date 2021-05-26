/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Ident = 258,
     IntLit = 259,
     Int = 260,
     Void = 261,
     Return = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     READ = 267,
     PRINT = 268,
     PRINTLINES = 269,
     PRINTSPACES = 270,
     EQ = 271,
     LESS_THAN = 272,
     GREATER_THAN = 273,
     LESS_THAN_EQUALS_TO = 274,
     GREATER_THAN_EQUALS_TO = 275,
     NOT_EQUAL = 276,
     NOT = 277,
     AND = 278,
     OR = 279
   };
#endif
/* Tokens.  */
#define Ident 258
#define IntLit 259
#define Int 260
#define Void 261
#define Return 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define READ 267
#define PRINT 268
#define PRINTLINES 269
#define PRINTSPACES 270
#define EQ 271
#define LESS_THAN 272
#define GREATER_THAN 273
#define LESS_THAN_EQUALS_TO 274
#define GREATER_THAN_EQUALS_TO 275
#define NOT_EQUAL 276
#define NOT 277
#define AND 278
#define OR 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "ExprEval.y"
{
  long val;
  char* string;
  struct expr_res_t* expr_res_t;
  struct instr_seq_t* instr_seq_t;
  struct b_expr_res_t* b_expr_res_t;
}
/* Line 1529 of yacc.c.  */
#line 105 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

