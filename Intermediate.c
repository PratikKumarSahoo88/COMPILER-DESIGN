#include <stdio.h>

#include <ctype.h>

char expr[50];

int temp = 1;

int index = 0;

/* Function to generate a new temporary variable */

void generate(char op, char arg1, char arg2)

{

    printf("t%d = %c %c %c\n", temp++, arg1, op, arg2);

}

int main()

{

    char arg1, arg2, op;

    printf("Enter the expression (single-letter operands): ");

    scanf("%s", expr);

    /* Simple TAC generation for expressions like a+b*c */

    arg1 = expr[0];

    for (index = 1; expr[index] != '\0'; index += 2)

    {

        op = expr[index];

        arg2 = expr[index + 1];

        generate(op, arg1, arg2);

        arg1 = 't';   /* Use temporary variable */

    }

    printf("Result stored in t%d\n", temp - 1);

    return 0;

}
