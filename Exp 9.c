#include <stdio.h>

#include <string.h>

struct variable

{

    char name[10];

    char type[10];

};

struct variable table[10];

int count = 0;

/* Add variable to symbol table */

void addVariable(char name[], char type[])

{

    strcpy(table[count].name, name);

    strcpy(table[count].type, type);

    count++;

}

/* Check type compatibility */

void checkType(char var1[], char var2[])

{

    int i, j;

    char type1[10], type2[10];



    for (i = 0; i < count; i++)

        if (strcmp(table[i].name, var1) == 0)

            strcpy(type1, table[i].type);

    for (j = 0; j<count; j++)

        if (strcmp(table[j].name, var2) == 0)

            strcpy(type2, table[j].type);

    if (strcmp(type1, type2) == 0)

        printf("Types are compatible (%s)\n", type1);

    else

    {

        printf("Type mismatch: %s and %s\n", type1, type2);

        printf("Type conversion required\n");

    }

}

int main()

{

    addVariable("a", "int");

    addVariable("b", "float");

    printf("Checking expression: a = b\n");

    checkType("a", "b");

    printf("\nChecking expression: a = a\n");

    checkType("a", "a");

    return 0;

}
