%{

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  int yyerror(const char *errormsg);
  void replacequotes(char* nstr);
  int yylex();
  int yyparse();
  int yywrap(){
      return 1;
  }
  extern FILE *yyout;
%}

%union
{
    char *str;
}
%token PROGRAM END VAR BEGINN PRINT INT SEMI COLON EQUAL 
%token <str> ID STRING COMMA NUM PLUS MINUS MULT DIVIDE OPENPARAN CLOSEPARAN
%type <str> pname id dec print output comma assign expr term factor openparan closeparan
%locations
%%

start: PROGRAM pname semi var dec_list semi begin stat_list end {fprintf(yyout,"return 0; \n }"); }
    |   { yyerror("'PROGRAM' expected."); exit(1); }
    ;

pname: id  {fprintf(yyout, "#include<iostream>\nint main(){\n");}
    |   { yyerror("program name <pname> expected."); exit(1); }
    ;

id: ID {  }
    ;

var: VAR   { fprintf(yyout, "int "); }
    |   { yyerror("'VAR' expected."); exit(1); }
    ;

dec_list: dec colon type    {fprintf(yyout, ";\n");}
    ;

dec:    id comma dec {fprintf(yyout, ", %s", $1);}
    |   id   {fprintf(yyout, "%s", $1); }
    ;

colon: COLON   { }
    |   { yyerror("colon ':' expected."); exit(1); }
    ;

semi: SEMI   {}
    |   { yyerror("SEMI ';' expected."); exit(1); }
    ;

type: INT   {  }
    |   { yyerror("keyword type of 'INT' expected."); exit(1); }
    ;

begin: BEGINN  { }
    |   { yyerror("keyword 'BEGIN' expected."); exit(1); }
    ;

stat_list: stat SEMI   {  }
    | stat SEMI stat_list  {  }
    ;

stat:  print     { }
    |  assign    {  }
    ;

print:   PRINT openparan output closeparan   {fprintf(yyout, "%s %s; \n ", $2, $3);}
    ;

openparan: OPENPARAN { $$="std::cout <<";}
    |   { yyerror("open parenthesis '(' expected."); exit(1); }
    ;

closeparan: CLOSEPARAN {}
    |   { yyerror("closed parenthesis ')' expected."); exit(1); }
    ;

output: id  { }
    |   STRING comma id { char* nstr=malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                strcpy(nstr,$1); replacequotes(nstr); strcat(nstr," << "); strcat(nstr,$3); 
                                $$=nstr; }
    ;

comma: COMMA {}
    |   { yyerror("',' expected."); exit(1); }
    ;

assign: id equal expr { fprintf(yyout, "%s = %s;\n", $1, $3); }
    ;

equal: EQUAL {  }
    |   { yyerror("assignment operator '=' expected."); exit(1); }
    ;

expr:  term         { }
    | expr PLUS term {char* nstr=malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                strcpy(nstr,$1);  strcat(nstr," + "); strcat(nstr,$3); 
                                $$=nstr; }
    | expr MINUS term { char* nstr=malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                strcpy(nstr,$1);  strcat(nstr," - "); strcat(nstr,$3); 
                                $$=nstr;  }
    ;

term:   term MULT factor { char* nstr=malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                strcpy(nstr,$1);  strcat(nstr," * "); strcat(nstr,$3); 
                                $$=nstr;}
    |   term DIVIDE factor {   char* nstr=malloc(sizeof(char)*(strlen($1)+strlen($3)+2));
                                strcpy(nstr,$1);  strcat(nstr," / "); strcat(nstr,$3); 
                                $$=nstr;   }
    |   factor          {  }
    ;

factor: id          {  }
    |   number      {  }
    |   '(' expr ')'{  }
    ;

number: NUM  { }
    ;

end: END {}
    |   { yyerror("keyword 'END.' expected."); exit(1); }
    ;

%%

void replacequotes(char* nstr){
    size_t n = sizeof(nstr)/sizeof(nstr[0]);
    for(int i=0;i<n;i++){
        if(nstr[i]=='\''){
            nstr[i]='\"';
        }
    }
}
