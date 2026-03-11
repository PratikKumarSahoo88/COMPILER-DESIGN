#include <stdio.h>

#include <string.h>

char stack[50], input[50];

int top = -1;

void push(char c)

{

    stack[++top] = c;

}

void pop()

{

    top--;

}

int main()

{

    int i = 0;

    char x;

    printf("Enter the input string (end with $): ");

    scanf("%s", input);

    push('$');

    push('E');

    printf("\nStack\t\tInput\t\tAction\n");

    while (top >= 0)

    {

        x = stack[top];

        printf("%s\t\t%s\t\t", stack,&input[i]);

        if (x == input[i])

        {

            pop();

            i++;

            printf("Match %c\n", x);

        }

        else

        {

            switch (x)

            {

                case 'E':

                    if (input[i] == 'i' || input[i] == '(')

                    {

                        pop();

                        push('E');

                        push('T');

                        printf("E ->TE'\n");

                    }

                    else goto error;

                    break;

                case 'T':

                    if (input[i] == 'i' || input[i] == '(')

                    {

                        pop();

                        push('T');

                        push('F');

                        printf("T ->FT'\n");

                    }

                    else goto error;

                    break;

                case 'F':

                    if (input[i] == 'i')

                    {

                        pop();

                        push('i');

                        printf("F ->id\n");

                    }

                    else if (input[i] == '(')

                    {

                        pop();

                        push(')');

                        push('E');

                        push('(');

                        printf("F ->(E)\n");

                    }

                    else goto error;

                    break;



                default:

                    goto error;

            }

        }



        if (x == '$' && input[i] == '$')

        {

            printf("\nString Accepted\n");

            return 0;

        }

    }



error:

    printf("\nString Rejected\n");

    return 0;

}












#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

void pop()
{
    top--;
}

int main()
{
    int i = 0;
    char x;

    printf("Enter the input string (end with $): ");
    scanf("%s", input);

    push('$');
    push('E');

    printf("\nStack\t\tInput\t\tAction\n");

    while (top >= 0)
    {
        x = stack[top];
        stack[top + 1] = '\0';

        printf("%s\t\t%s\t\t", stack, &input[i]);

        if (x == input[i])
        {
            pop();
            i++;
            printf("Match %c\n", x);
        }
        else
        {
            switch (x)
            {
            case 'E':
                if (input[i] == 'i' || input[i] == '(')
                {
                    pop();
                    push('A');   // E'
                    push('T');
                    printf("E -> T E'\n");
                }
                else goto error;
                break;

            case 'A':   // E'
                if (input[i] == '+')
                {
                    pop();
                    push('A');
                    push('T');
                    push('+');
                    printf("E' -> + T E'\n");
                }
                else if (input[i] == ')' || input[i] == '$')
                {
                    pop();
                    printf("E' -> ε\n");
                }
                else goto error;
                break;

            case 'T':
                if (input[i] == 'i' || input[i] == '(')
                {
                    pop();
                    push('B');   // T'
                    push('F');
                    printf("T -> F T'\n");
                }
                else goto error;
                break;

            case 'B':   // T'
                if (input[i] == '*')
                {
                    pop();
                    push('B');
                    push('F');
                    push('*');
                    printf("T' -> * F T'\n");
                }
                else if (input[i] == '+' || input[i] == ')' || input[i] == '$')
                {
                    pop();
                    printf("T' -> ε\n");
                }
                else goto error;
                break;

            case 'F':
                if (input[i] == 'i')
                {
                    pop();
                    push('i');
                    printf("F -> i\n");
                }
                else if (input[i] == '(')
                {
                    pop();
                    push(')');
                    push('E');
                    push('(');
                    printf("F -> (E)\n");
                }
                else goto error;
                break;

            default:
                goto error;
            }
        }

        if (x == '$' && input[i] == '$')
        {
            printf("\nString Accepted\n");
            return 0;
        }
    }

error:
    printf("\nString Rejected\n");
    return 0;
}
