#include<stdio.h>

#include<string.h>



#define MAX 100



int stack[MAX];

int top = -1;

char input[MAX];

int ip = 0;



void push(int x) {

    stack[++top] = x;

}



void pop(int n) {

    top -= n;

}



/*

LALR ACTION TABLE

s = shift, r = reduce, acc = accept

*/



char* action(int state, char symbol) {

    switch(state) {

        case 0:

            if(symbol=='i') return "s5";

            break;



        case 1:

            if(symbol=='+') return "s6";

            if(symbol=='$') return "acc";

            break;



        case 2:

            if(symbol=='+') return "r2";

            if(symbol=='*') return "s7";

            if(symbol=='$') return "r2";

            break;



        case 3:

            if(symbol=='+') return "r4";

            if(symbol=='*') return "r4";

            if(symbol=='$') return "r4";

            break;



        case 5:

            if(symbol=='+') return "r6";

            if(symbol=='*') return "r6";

            if(symbol=='$') return "r6";

            break;



        case 6:

            if(symbol=='i') return "s5";

            break;



        case 7:

            if(symbol=='i') return "s5";

            break;



        case 8:

            if(symbol=='+') return "s6";

            if(symbol=='$') return "r1";

            break;



        case 9:

            if(symbol=='+') return "r1";

            if(symbol=='*') return "s7";

            if(symbol=='$') return "r1";

            break;



        case 10:

            if(symbol=='+') return "r3";

            if(symbol=='*') return "r3";

            if(symbol=='$') return "r3";

            break;

    }

    return "";

}



/*

LALR GOTO TABLE

*/

int goTo(int state, char symbol) {

    switch(state) {

        case 0:

            if(symbol=='E') return 1;

            if(symbol=='T') return 2;

            if(symbol=='F') return 3;

            break;



        case 6:

            if(symbol=='T') return 9;

            if(symbol=='F') return 3;

            break;



        case 7:

            if(symbol=='F') return 10;

            break;

    }

    return -1;

}



// RHS lengths

int ruleLength(int rule) {

    switch(rule) {

        case 1: return 3; // E→E+T

        case 2: return 1; // E→T

        case 3: return 3; // T→T*F

        case 4: return 1; // T→F

        case 6: return 1; // F→i

    }

    return 0;

}



// LHS symbols

char lhs(int rule) {

    switch(rule) {

        case 1:

        case 2: return 'E';

        case 3:

        case 4: return 'T';

        case 6: return 'F';

    }

    return ' ';

}



int main() {

    printf("Enter input string (use i for id, end with $): ");

    scanf("%s", input);



    push(0);



    printf("\nStack\tInput\tAction\n");



    while(1) {

        int state = stack[top];

        char symbol = input[ip];



        char *act = action(state, symbol);



        printf("%d\t%s\t", state,&input[ip]);



        // SHIFT

        if(act[0]=='s') {

            int next = act[1]-'0';

            printf("Shift %c\n", symbol);

            push(next);

            ip++;

        }



        // REDUCE

        else if(act[0]=='r') {

            int rule = act[1]-'0';

            printf("Reduce by rule %d\n", rule);



            int len = ruleLength(rule);

            pop(len);



            int newState = stack[top];

            int gotoState = goTo(newState, lhs(rule));



            push(gotoState);

        }



        // ACCEPT

        else if(strcmp(act, "acc")==0) {

            printf("Accepted\n");

            break;

        }



        else {

            printf("Error\n");

            break;

        }

    }



    return 0;

}
