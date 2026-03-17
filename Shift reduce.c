#include<stdio.h>

#include<string.h>

char stack[50];

char input[50];

int top = -1;



void shift(char symbol)

{

    stack[++top] = symbol;

    stack[top + 1] = '\0';

}



void reduce()

{

    int reduced;

    do

    {

        reduced = 0;

        // Reduce by E→ id

        if (top >= 1 && stack[top] == 'd' && stack[top - 1] == 'i')

        {

            stack[top - 1] = 'E';

            top--;

            stack[top + 1] = '\0';

            printf("Reduce: E ->id\n");

            reduced = 1;

        }

        // Reduce by E → E*E (higher precedence first)

        else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E')

        {

            stack[top - 2] = 'E';

            top -= 2;

            stack[top + 1] = '\0';

            printf("Reduce: E ->E*E\n");

            reduced = 1;

        }

        // Reduce by E → E+E        

else if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E')

        {

            stack[top - 2] = 'E';

            top -= 2;

            stack[top + 1] = '\0';

            printf("Reduce: E ->E+E\n");

            reduced = 1;

        }



    } while (reduced); // Keep reducing

}

int main()

{

    int i = 0;

    printf("Enter the input string (end with $): ");

    scanf("%s", input);

    printf("\nStack\t\tInput\t\tAction\n");

    while (input[i] != '\0')

    {

        shift(input[i]);

        printf("%s\t\t%s\t\tShift %c\n", stack, &input[i + 1], input[i]);

        i++;

        reduce(); // Apply all possible reductions

    }

    reduce();

    if (top == 0 && stack[top] == 'E')

        printf("\nString Accepted\n");

    else

        printf("\nString Rejected\n");

    return 0;

}
