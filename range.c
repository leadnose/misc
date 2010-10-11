#include <stdio.h>
#include <stdlib.h>

static
int parse_int(const char *s)
{
    int result;

    if (1 == sscanf(s, "%d", &result)) {
        return result;
    } else {
        // Write error message to stderr and exit right away
        fprintf(stderr, "Couldn't parse int from string %s\nExiting.\n", s);
        exit(EXIT_FAILURE);
    }
}

static
void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s lower-bound upper-bound\n.", progname);
}

int main(int argc, char *argv[]) 
{
    int i;

    if (3 == argc) {
        
        int lbound = parse_int(argv[1]);
        int ubound = parse_int(argv[2]);
        
        for (i = lbound; i < ubound; ++i)
            printf("%d\n", i);

        exit(EXIT_SUCCESS);
        
    } else {
        
        usage(argv[0]);
        exit(EXIT_FAILURE);
        
    }
    
}
