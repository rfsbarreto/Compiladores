typedef enum {MNG_PROG,MNG_DEC,MNG_DECVAR,MNG_LISTNOM,MNG_TIPO,
MNG_TIPBASE,MNG_DECFUNC,MNG_PARS, MNG_IF, MNG_WHILE,
MNG_ATRIB, MNG_OP, MNG_NAO, MNG_TIPEXP, MNG_RETURN, 
MNG_OPNEG,MNG_PAR,MNG_BLOCO,MNG_DECVARS,MNG_CMD,
MNG_CMDS,MNG_PTELSE,MNG_VAR,MNG_EXP,MNG_CHMET,MNG_LSTEXP} tipo_no;


typedef enum mng_tipbase { 
	TIPO_INT,TIPO_CHAR,TIPO_STRING,TIPO_FLOAT,TIPO_VAZIO
} mng_tipbase ; //tipobase

typedef enum mng_operadores { 
	OP_NAO, OP_SOMA, OP_SUB, OP_MULT, OP_DIV, OP_IGUAL, OP_MENORIG, OP_MAIORIG, OP_MENORQ, OP_MAIORQ, OP_OU, OP_E
} mng_operadores ; //operadores

typedef enum mng_tipret { 
	RET_VAZIO, RET_EXP
} mng_tipret ; //tiporet
