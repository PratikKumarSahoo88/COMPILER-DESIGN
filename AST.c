#include <stdio.h>

#include <stdlib.h>

#include <string.h>

/* Structure of AST Node */

struct ASTNode

{

    char value;

    struct ASTNode *left;

    struct ASTNode *right;

};

/* Function to create a new AST node */

struct ASTNode* createNode(char val)

{

    struct ASTNode* node = (struct ASTNode*)malloc(sizeof(struct ASTNode));

    node->value = val;

    node->left = NULL;

    node->right = NULL;

    return node;

}

/* Function to print AST using inorder traversal */

void inorder(struct ASTNode* root)

{

    if (root != NULL)

    {

        inorder(root->left);

        printf("%c ", root->value);

        inorder(root->right);

    }

}

int main()

{

    /* Creating AST for expression: a + b * c */

    struct ASTNode* a = createNode('a');

    struct ASTNode* b = createNode('b');

    struct ASTNode* c = createNode('c');

    struct ASTNode* mul = createNode('*');

    mul->left = b;

    mul->right = c;

    struct ASTNode* plus = createNode('+');

    plus->left = a;

    plus->right = mul;

    printf("Inorder Traversal of AST:\n");

    inorder(plus);

    printf("\n");

    return 0;

}


