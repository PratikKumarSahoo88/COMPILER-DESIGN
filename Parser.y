%{

#include<stdio.h>

int yylex();

void yyerror(const char *s);

%}



%token NUM ID IF ELSE WHILE

%left '+' '-'

%left '*' '/'



%%

stmt : expr '

' { printf("Valid Expression

"); }

     | IF '(' expr ')' stmt ELSE stmt

     | WHILE '(' expr ')' stmt

     ;



expr : expr '+' expr

     | expr '*' expr

     | NUM

     | ID

     ;

%%



void yyerror(const char *s) { 

printf("Syntax Error"); }

int main() { return yyparse(); }
