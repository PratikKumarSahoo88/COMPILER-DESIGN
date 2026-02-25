#include <stdio.h>

#include <string.h>

int main()

{

    char nonTerminal;

    char prod1[20], prod2[20];

    int i = 0;

    printf("Enter the non-terminal: ");

    scanf(" %c",&nonTerminal);

    printf("Enter first production: ");

    scanf("%s", prod1);

    printf("Enter second production: ");

    scanf("%s", prod2);

    printf("\nOriginal Grammar:\n");

    printf("%c ->%s | %s\n", nonTerminal, prod1, prod2);

    while (prod1[i] == prod2[i])

        i++;

    printf("\nGrammar after Left Factoring:\n");

    printf("%c ->", nonTerminal);

    for (int j = 0; j < i; j++)

        printf("%c", prod1[j]);

    printf("%c'\n", nonTerminal);

    printf("%c' ->%s | %s\n",

           nonTerminal,

           prod1 + i,

           prod2 + i);

    return 0;

}
