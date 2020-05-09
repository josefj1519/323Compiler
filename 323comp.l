  
%{
  #include "y.tab.h"
   
%}

string '.*'
id     [a-f][a-f0-9]*
number [0-9]+

%option yylineno
%%
{string}       yylval.str=strdup(yytext);return STRING;
PROGRAM        return PROGRAM;
VAR            return VAR;
INTEGER        return INT;
BEGIN          return BEGINN;
PRINT          return PRINT;
"END."         return END;
{number}       yylval.str=strdup(yytext);return NUM;
{id}           yylval.str=strdup(yytext);return ID;
"("            yylval.str=strdup(yytext);return OPENPARAN;
")"            yylval.str=strdup(yytext);return CLOSEPARAN;
"+"            yylval.str=strdup(yytext); return PLUS ;      
"-"            yylval.str=strdup(yytext);return MINUS;
"*"            yylval.str=strdup(yytext);return MULT;
"/"            return DIVIDE;
,              yylval.str=strdup(yytext);return COMMA;
;              return SEMI;
:              return COLON;
=              return EQUAL;
\n              
[ \t]+          
                                       
%%
int main(){
    yyin = fopen("interim.txt", "r");
    yyout = fopen("323comp.cc", "w");
    yyparse();
    fclose(yyout);
    fclose(yyin);
 }
int yyerror(const char *errormsg){
      fprintf(stderr, "Line: %d\n%s\n",yylineno,errormsg);
      exit(1);
}

