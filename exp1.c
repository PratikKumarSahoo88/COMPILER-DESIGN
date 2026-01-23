// #include <stdio.h>
// #define MAX_LEN 1024
// int main(){
//     char ch;
//     int charcount=0,word_count=0,line_count=0;
//     int in_word=0;
//     char file_name[MAX_LEN];
//     FILE *fp;
//     printf("Enter a file name:");
//     scanf("%s",file_name);
//     fp=fopen(file_name,"r");
//     if(fp==NULL){
//         printf("could not open the file %s\n",file_name);
//         return 1;
//     }
//     while((ch=fgetc(fp))!=EOF){
//         charcount ++;
//         if(ch==' '||ch=='\t'||ch=='\0'||ch=='\n'){
//             if(in_word){
//                 in_word=0;
//                 word_count++;
//             }
//             if(ch='\0'||ch=='\n')
//             line_count++;
//         }
//         else{
//             in_word=1;
//         }
//     }
//     printf("In the file%s:\n",file_name);
//     printf("Number of characters :%d\n",charcount);
//     printf("Number of words:%d\n",word_count);
//     printf("Number of Lines:%d\n",line_count);
// }


#include <stdio.h>
#define MAX_LEN 1024

int main() {
    int ch;
    int charcount = 0, word_count = 0, line_count = 0;
    int in_word = 0;
    char file_name[MAX_LEN];
    FILE *fp;

    printf("Enter a file name: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Could not open the file %s\n", file_name);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        charcount++;

        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
            if (ch == '\n') {
                line_count++;
            }
        } else {
            in_word = 1;
        }
    }

    // Count last word if file doesn't end with space/newline
    if (in_word) {
        word_count++;
    }

    fclose(fp);

    printf("In the file %s:\n", file_name);
    printf("Number of characters: %d\n", charcount);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
}
