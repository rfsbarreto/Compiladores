/*** Definition section ***/

%{
/* C code to be copied verbatim */
#include <stdio.h>

#include "sint.h"
//#include "teste.h"
//extern YYSTYPE yylval ;

int lineno = 1;
int i=0;
char* c;

char* deslocando(int i, char* c, int tam){
	int j=i+1;
	while (j<tam-1){
		c[j] = c[j+1];
		j++;
	}
	c[tam-1] = '\0';
	return c;
}


%}

/* This tells flex to read only one input file */
%option noyywrap


digito [0-9]
letra [a-zA-Z]
numero {digito}+
hexa 0x[A-F0-9a-f]*
id [a-zA-Z_]+[a-zA-Z0-9_]*
aspas \"
tudo .*
enter \n
AComment "/*"
FComment "*/"
Comment "//"(.*)$ 

Comentario [^{FComment}]
ErroComment {AComment}{tudo}[^{FComment}]


String [^\n"\""]|"\\\"" 



%%
	/*** Rules section ***/

    
char	 	{ return CHAR; }
else	 	{ return ELSE; }
float 	{ return FLOAT; }   
if    	{ return IF; }  
int   	{ return INT; }  
new   	{ return NEW; }  
return	{ return RETURN; }  
void  	{ return VOID; }  
while	{ return WHILE ; }
"("		{ return APAR;}
")"		{ return FPAR;}
"{"		{ return ACHAVE;}
"}"		{ return FCHAVE;}
"["		{ return ACOL;}
"]"		{ return FCOL;}
","		{ return VIRG;}
";"		{ return PTVIRG;}
"="		{ ; return ATRIB;}
"=="		{ return IGUAL;}
"+"		{ return SOMA;}
"-"		{ return SUB;}
"/"		{ return DIV;}
"*"		{ return MULT;}
">"		{ return MAIORQ;}
"<"		{ return MENORQ;}
">="		{ return MAIORIG;}
"<="		{ return MENORIG;}
"!"		{ return NAO;}
"||"		{ return OU;}
"&&"		{ return E;}
" "		{}
\t      {}
\r      {}
\n      {lineno++; }
{id} { int tamanho = strlen(yytext)*sizeof(char);
	//mng_id* i=(mng_id*) malloc(tamanho);
	//(*i).name="";
          // strcat((*i).name,yytext);
		//yylval->string = (char *) malloc(tamanho); 
	  //      mng_id id1 ; //= (mng_id) malloc(sizeof(mng_id); //malloc(80*sizeof(char)); //malloc(sizeof(mng_id));
	//	strcpy(id1.name,yytext);
	//	id1.name=yytext;
	//	printf("12341: %s\n",id1.name);
		//char* aux="";	
	//	strcat(id1.name,"12");
//		char* aux = yytext;
//		yylval.id.name="";
	//	strcpy(yylval.id,x);
	//	yylval= (YYSTYPE)  id1;    //yyget_text(); //strcat(yytext,"1");
	yylval.id.name=(char *) malloc(tamanho);
	strcat(yylval.id.name,yytext);
	//printf("KK: %s \n" , yylval.id.name);
		
		//strcat(yylval->string,yytext);		
		return ID; 	
		}
		
{numero}|{hexa}  	{   //yylval->inteiro = atoi(yytext); 	
						mng_numint* aux= (mng_numint*) malloc(sizeof(mng_numint));
						(*aux).valor=atoi(yytext);
						yylval.numint=*aux;	
						
						//yylval= (YYSTYPE) atoi(yytext); 		
								return NUMINT;}
								
{numero}"."{digito}*|{digito}*"."{numero} { //yylval->real= atof(yytext);; yylval.
						mng_numfloat* aux= (mng_numfloat*) malloc(sizeof(mng_numfloat));
						(*aux).valor=atof(yytext);
						yylval.numfloat=*aux;	
						//yylval.numint.valor= (YYSTYPE)atof(yytext);
															return NUMFLOAT;}	

															
{AComment}  {  int linha = lineno;
						char c=input();
						int fechou = 0;
						while(c!=EOF){
							if(c == '\n'){
								lineno++;
							}
							if(c == '*'){	
								c=input();
								if(c == '/'){	
									fechou = 1;
									break;
								}
							}else
							c=input();
						}
						if(fechou == 0){
							fprintf(stderr,"ERRO: Comentário não fechado na linha %d ", linha); return;
						}						
					}
										

{aspas}{String}*{aspas}  { 	c=yytext;
									i=0;
									int j = 0;
									int tam = yyleng;
						
									while(i<tam-1){
										if(c[i] == '\\'){
											switch(c[i+1]){
											case 'n':	c[i] = '\n';
															c= deslocando(i, c,tam);
															tam--;
															break;
											case 't': 	c[i] = '\t';
												            c= deslocando(i, c,tam);
															tam--;
															break;
											case '\\': 	c[i] = '\\';
															c= deslocando(i, c,tam);
															tam--;
															break;
											case '\"':   	c[i] = '\"';
															c= deslocando(i, c,tam);
															tam--;
															break;
											default:;	
											}
										}
										i++;
									}
								int tamanho = strlen(yytext) *sizeof(char);
								mng_string* aux= (mng_string*) malloc(sizeof(tamanho));
								(*aux).valor=yytext;
//								(*aux).tam=strlen(yytext);
																		
								if ( strlen(yytext)>1 ){
									(*aux).tipo=TIPO_STRING;	
									yylval.string=*aux;	
								} else {
									(*aux).tipo=TIPO_CHAR;
									(*aux).valor= yytext;
									yylval.string=*aux;	
								}
							
//									yylval = (YYSTYPE) yytext;		
									return STRING;
									} 
{aspas}{String}*  { fprintf(stderr,"ERRO: String não fechada na linha %d ", lineno); return;} 


.    {fprintf(stderr,"ERRO: Caracter inválido %d ", lineno); return; }


%%
/*** C Code section ***/
/*
int main(char* args[],char* argv[])
{
   

	yylex();
    return 0;
	
}
*/
