#include <stdio.h>

#include <string.h>

struct activationRecord

{

    char functionName[20];

    int returnAddress;

};

struct activationRecord stack[10];

int top = -1;

/* Push activation record */

void push(char fname[], int retAddr)

{

    top++;

    strcpy(stack[top].functionName, fname);

    stack[top].returnAddress = retAddr;

}

/* Pop activation record */

void pop()

{

    printf("Returning from function: %s\n", stack[top].functionName);

    top--;

}

/* Display runtime stack */

void display()

{

    printf("\nRuntime Stack:\n");

    printf("Function Name\tReturn Address\n");

    for (int i = top; i >= 0; i--)

        printf("%s\t\t%d\n", stack[i].functionName, stack[i].returnAddress);

}



void main()

{

    printf("Simulating Runtime Environment\n");

    push("main()", 0);

    display();

    push("fun1()", 100);

    display();

    push("fun2()", 200);

    display();

    pop();

    display();

    pop();

    display();

    pop();

    display();

}
