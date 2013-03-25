/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     CHAR = 258,
     ELSE = 259,
     FLOAT = 260,
     IF = 261,
     INT = 262,
     NEW = 263,
     RETURN = 264,
     VOID = 265,
     WHILE = 266,
     NUMINT = 267,
     NUMFLOAT = 268,
     STRING = 269,
     ID = 270,
     PTVIRG = 271,
     VIRG = 272,
     ACOL = 273,
     FCOL = 274,
     APAR = 275,
     FPAR = 276,
     ACHAVE = 277,
     FCHAVE = 278,
     SOMA = 279,
     SUB = 280,
     MULT = 281,
     DIV = 282,
     ATRIB = 283,
     IGUAL = 284,
     MENORIG = 285,
     MAIORIG = 286,
     MENORQ = 287,
     MAIORQ = 288,
     NAO = 289,
     E = 290,
     OU = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 32 "bison.y"

	
	mng_tipbase  tipbase;	
	mng_id id;
	mng_var var;
	DEC(bloco);
	mng_pars * pars;
	mng_par par;
	mng_decvar decvar;
	mng_decfunc decfunc;
	mng_tip tip;
	mng_prg* prg;
	mng_dec dec;
	mng_listnom* listnom;
	mng_decvars* decvars;
	mng_cmds* cmds;
	mng_cmd cmd;
	mng_ptelse* ptelse;
	mng_chmet chmet;
	mng_listexp* listexp;
	mng_exp exp;
	DEC(numint);
	DEC(numfloat);
	DEC(string);
	DEC(chr);
	//DEC(prg);
	//int token;



/* Line 2068 of yacc.c  */
#line 117 "sint.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


