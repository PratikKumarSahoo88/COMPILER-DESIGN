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










#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    if (top >= 0) top--;
}

void display_stack() {
    for (int j = 0; j <= top; j++) printf("%c", stack[j]);
}

int main() {
    int i = 0;
    char x;
    printf("Enter the input string (e.g., i+i*i$): ");
    scanf("%s", input);

    push('$');
    push('E');

    printf("\nStack\t\tInput\t\tAction\n");
    printf("----------------------------------------------\n");

    while (top >= 0) {
        x = stack[top];
        
        display_stack();
        printf("\t\t%s\t\t", &input[i]);

        if (x == input[i]) {
            pop();
            i++;
            printf("Match %c\n", x);
            if (x == '$') {
                printf("\nString Accepted\n");
                return 0;
            }
        } 
        else if (x == '#') { // # represents Epsilon (empty string)
            pop();
            printf("Pop Epsilon\n");
        }
        else {
            pop(); // Pop the non-terminal to replace it with production
            switch (x) {
                case 'E':
                    if (input[i] == 'i' || input[i] == '(') {
                        push('e'); // 'e' represents E'
                        push('T');
                        printf("E -> Te\n");
                    } else goto error;
                    break;
                case 'e': // E'
                    if (input[i] == '+') {
                        push('e');
                        push('T');
                        push('+');
                        printf("E' -> +Te\n");
                    } else { // E' -> epsilon
                        push('#');
                        printf("E' -> #\n");
                    }
                    break;
                case 'T':
                    if (input[i] == 'i' || input[i] == '(') {
                        push('t'); // 't' represents T'
                        push('F');
                        printf("T -> Ft\n");
                    } else goto error;
                    break;
                case 't': // T'
                    if (input[i] == '*') {
                        push('t');
                        push('F');
                        push('*');
                        printf("T' -> *Ft\n");
                    } else { // T' -> epsilon
                        push('#');
                        printf("T' -> #\n");
                    }
                    break;
                case 'F':
                    if (input[i] == 'i') {
                        push('i');
                        printf("F -> i\n");
                    } else if (input[i] == '(') {
                        push(')');
                        push('E');
                        push('(');
                        printf("F -> (E)\n");
                    } else goto error;
                    break;
                default:
                    goto error;
            }
        }
    }

error:
    printf("\nString Rejected\n");
    return 0;
}
