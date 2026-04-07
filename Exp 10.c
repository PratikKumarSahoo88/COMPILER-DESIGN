#include <stdio.h>

/* Constant Folding */

void constantFolding()

{

    int a;

    a = 3 * 4;

    printf("After Constant Folding: a = %d\n", a);

}

/* Dead Code Elimination */

void deadCodeElimination()

{

    int x = 10;

    int y = 20;

    x = x + 5;   // useful statement

    // y is never used

    printf("After Dead Code Elimination: x = %d\n", x);

}

/* Strength Reduction */

void strengthReduction()

{

    int i, x = 5;

    printf("After Strength Reduction:\n");

    for (i = 0; i < 4; i++)

    {

        x = x << 1;   // x = x * 2

        printf("x = %d\n", x);

    }

}

void main()

{

    printf("Basic Code Optimization Techniques\n\n");

    constantFolding();

    deadCodeElimination();

    strengthReduction();

}
