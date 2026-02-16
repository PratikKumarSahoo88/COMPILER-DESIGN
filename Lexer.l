%{

#include<stdio.h>

#include<stdlib.h>

%}

/* Definitions */

DIGIT   [0-9]

ID      [a-zA-Z_][a-zA-Z0-9_]*

%%

/* Keywords */

int|float|char|if|else|while|for|return

        { printf("KEYWORD : %s\n", yytext); }

/* Identifiers */

{ID}    { printf("IDENTIFIER : %s\n", yytext); }

/* Numbers */

{DIGIT}+    { printf("NUMBER : %s\n", yytext); }

/* Operators */

"+"|"-"|"*"|"/"|"="|"=="|"!="|"<"|">"|"<="|">="

        { printf("OPERATOR : %s\n", yytext); }

/* Special Symbols */

";"|","|"("|")"|"{"|"}"

        { printf("SYMBOL : %s\n", yytext); }

/* Ignore spaces and tabs */

[ \t\n]+    ;

/* Any other character */

.       { printf("UNKNOWN : %s\n", yytext); }

%%

void main()

{

    yylex();

}
