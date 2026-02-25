#include<stdio.h>

#include<string.h>

int main()

{

    char nonTerminal;

    char alpha[20], beta[20];

    printf("Enter the non-terminal: ");

    scanf(" %c",&nonTerminal);

    printf("Enter alpha (for A->Aalpha): ");

    scanf("%s", alpha);

    printf("Enter beta (for A->beta): ");

    scanf("%s", beta);

    printf("\nOriginal Grammar:\n");

    printf("%c ->%c%s | %s\n", nonTerminal, nonTerminal, alpha, beta);

    printf("\nGrammar after removing left recursion:\n");

    printf("%c ->%s%c'\n", nonTerminal, beta, nonTerminal);

    printf("%c' ->%s%c' | ε\n", nonTerminal, alpha, nonTerminal);

    return 0;

}
