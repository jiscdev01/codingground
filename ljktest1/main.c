#include <stdio.h>
#include "module1.h"


int main(int argc, char *argv[])
{
    printf("Hello, World!\n");

    unsigned int i = 1;
    
    if( argc >= 2 )
    {
        printf("Your input is : %d\n", i);
        i = atoi(argv[1]);
    }

    double f = factorial(i);
    printf("factorial(%d) is %.4f\n", i, f);

    return 0;
}

