#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; ++i)
        puts(argv[i]);
    
    return EXIT_SUCCESS;
}
