#include <stdio.h>

#include <string.h>

struct symbol

{

    char name[20];

    char type[10];

    int address;

};

struct symbol table[50];

int count = 0;

/* Insert a new symbol */

void insert()

{

    printf("Enter symbol name: ");

    scanf("%s", table[count].name);

    printf("Enter data type: ");

    scanf("%s", table[count].type);

    table[count].address = count * 4;

    count++;

    printf("Symbol inserted successfully\n");

}

/* Search for a symbol */

void search()

{

    char name[20];

    int found = 0;

    printf("Enter symbol name to search: ");

    scanf("%s", name);

    

	for (int i = 0; i < count; i++)

    {

        if (strcmp(table[i].name, name) == 0)

        {

            printf("Symbol Found\n");

            printf("Name: %s\n", table[i].name);

            printf("Type: %s\n", table[i].type);

            printf("Address: %d\n", table[i].address);

            found = 1;

            break;

        }

    }

    if (!found)

        printf("Symbol not found\n");

}

/* Display symbol table */

void display()

{

    printf("\nSymbol Table\n");

    printf("Name\tType\tAddress\n");

    for (int i = 0; i < count; i++)

        printf("%s\t%s\t%d\n", table[i].name, table[i].type, table[i].address);

}

int main()

{

    int choice;

    while (1)

    {

        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");

        printf("Enter your choice: ");

        scanf("%d",&choice);

        switch (choice)

        {

            case 1: insert(); break;

            case 2: search(); break;

            case 3: display(); break;

            case 4: return 0;

            default: printf("Invalid choice\n");

        }

    }

}


