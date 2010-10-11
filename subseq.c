#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static
void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s lower-bound upper-bound\n", progname);
}

static
void skipline(void)
{
    for (;;) {
        int c = getchar();
        if (EOF == c) {
            exit(EXIT_FAILURE);
        } else if ('\n' == c) {
            return;
        }
    }
}

static
void printline(void)
{
    for (;;) {
        int c = getchar();
        if (EOF == c) {
            exit(EXIT_FAILURE);
        }
        putchar(c);
        
        if ('\n' == c) {
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    if (3 != argc) {

        usage(argv[0]);
        exit(EXIT_FAILURE);

    } else {

        assert(3 == argc);

        int lb, ub;

        if (! (sscanf(argv[1], "%d", &lb) && sscanf(argv[2], "%d", &ub))) {

            fprintf(stderr, "The arguments must be numbers.\n");
            usage(argv[0]);
            exit(EXIT_FAILURE);

        } else if (lb > ub) {

            fprintf(stderr, "The lower-bound must be less than or equal to than upper-bound (duh!).\n");
            usage(argv[0]);
            exit(EXIT_FAILURE);

        } else if (lb == ub) {

            exit(EXIT_SUCCESS);

        } else {

            assert(lb <= ub);

            int newlines = 0;

            while (newlines++ < lb) {
                skipline();
            }

            newlines = 0;

            while (newlines++ < (ub - lb)) {
                printline();
            }

            exit(EXIT_SUCCESS);
        }
    }    
}
