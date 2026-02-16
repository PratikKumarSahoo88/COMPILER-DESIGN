#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int iskeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto","break","case","char","const","continue","default","do",
        "double","else","enum","extern","float","for","goto","if","int",
        "long","register","return","short","signed","sizeof","static",
        "struct","switch","typedef","union","unsigned","void","volatile","while"
    };

    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%="; // Removed spaces from operator string
    FILE *fp;
    int i, j = 0;
    
    fp = fopen("aprogram.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    // Use int for ch to properly handle EOF
    int c; 
    while ((c = fgetc(fp)) != EOF) {
        ch = (char)c;

        // 1. Check if it's an operator
        for (i = 0; i < 6; i++) {
            if (ch == operators[i]) {
                printf("%c is operator\n", ch);
            }
        }

        // 2. Build identifier / keyword
        if (isalnum(ch)) {
            if (j < 14) { // Prevent overflow
                buffer[j++] = ch;
            }
        } 
        // 3. If delimiter (space, newline, or operator), process the buffer
        else if ((isspace(ch) || strchr(operators, ch)) && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if (iskeyword(buffer))
                printf("%s is keyword\n", buffer);
            else
                printf("%s is identifier\n", buffer);
        }
    }

    // Handle the very last token if the file doesn't end in a space/newline
    if (j > 0) {
        buffer[j] = '\0';
        if (iskeyword(buffer))
            printf("%s is keyword\n", buffer);
        else
            printf("%s is identifier\n", buffer);
    }

    fclose(fp);
    return 0;
}
