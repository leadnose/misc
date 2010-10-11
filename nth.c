#include <stdio.h>
#include <stdlib.h>

static 
int from_stdin(int n)
{
    int lines = 0;

    while (lines < n) {
        int c = getchar();
        if (EOF == c)
            return EXIT_FAILURE;
        if ('\n' == c) lines++;
    }


    for (;;) {
        int c = getchar();
        if (EOF == c) 
            return EXIT_SUCCESS;
        if ('\n' == c) {
            putchar(c);
            return EXIT_SUCCESS;
        }
        putchar(c);
    }

    return EXIT_SUCCESS;
}

static
void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s n\n", progname);
}

int main(int argc, char *argv[])
{
    if (2 == argc) {

        int n;

        if (1 == sscanf(argv[1], "%d", &n)) {
            if (n >= 0) {
                return from_stdin(n);
            } else {
                fprintf(stderr, "n must be non-negative.\n");
                return EXIT_FAILURE;
            }            
        } else {
            fprintf(stderr, "could not parse n.\n");
            return EXIT_FAILURE;
        }

    } else {

        usage(argv[0]);
        return EXIT_FAILURE;

    }
}
