%{
#include<stdio.h>
#include<stdlib.h>
%}

DIGIT   [0-9]
ID      [a-zA-Z_][a-zA-Z0-9_]*

%%
int|float|char|if|else|while|for|return { printf("KEYWORD : %s\n", yytext); }
{ID}    { printf("IDENTIFIER : %s\n", yytext); }
{DIGIT}+    { printf("NUMBER : %s\n", yytext); }
"+"|"-"|"*"|"/"|"="|"=="|"!="|"<"|">"|"<="|">="  { printf("OPERATOR : %s\n", yytext); }
";"|","|"("|")"|"{"|"}"   { printf("SYMBOL : %s\n", yytext); }
[ \t\n]+    ;
.       { printf("UNKNOWN : %s\n", yytext); }
%%

int main()
{
    yylex();
    return 0;
}
int yywrap(){
   return 1;
   }
