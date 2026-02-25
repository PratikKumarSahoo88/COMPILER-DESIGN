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












%{

#include<stdio.h>

#include<stdlib.h>



int yylex();

void yyerror(const char *s);

%}



%token NUM ID IF ELSE WHILE



%left '+' '-'

%left '*' '/'



%%



stmt:

        expr '\n'{ printf("Valid Expression\n"); }

      | IF '(' expr ')' stmt ELSE stmt

      | WHILE '(' expr ')' stmt

      ;



expr:

        expr '+' expr

      | expr '-' expr

      | expr '*' expr

      | expr '/' expr

      | '(' expr ')'

      | NUM

      | ID

      ;



%%



void yyerror(const char *s)

{

    printf("Syntax Error\n");

}



int main()

{

    printf("Enter input:\n");

    return yyparse();

}


