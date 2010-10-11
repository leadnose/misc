#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iostream>

#include <stdio.h>

using namespace ::std;


static
int parse_int(const string& s)
{
    int result;

    if (1 == sscanf(s.c_str(), "%d", &result)) {
        return result;
    } else {
        // Write error message to stderr and exit right away
        fprintf(stderr, "Couldn't parse int from string %s\nExiting.\n", s.c_str());
        exit(EXIT_FAILURE);
    }
}

static
void from_stdin()
{
    int result = 0;

    while (!cin.eof()) {
        int i;
        cin >> i;
        if (cin.eof())
            break;
        if (!cin.good()) {
            fprintf(stderr, "Failed to parse int. Exiting.\n");
            exit(EXIT_FAILURE);
        }
        result -= i;
    }

    printf("%d\n", result);
}

static
int minus_int(int a, int b)
{
    return a - b;
}

static void from_args(const vector<string>& sv) 
{
    vector<int> iv(sv.size());

    transform(sv.begin(), sv.end(), iv.begin(), parse_int);

    int result = iv[0];

    for (auto it = ++iv.begin(); it != iv.end(); ++it) 
        result -= *it;

    printf("%d\n", result);
}

static void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s number [more numbers]\n", progname);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    vector<string> sv(argv + 1, argv + argc);

    if (0 == sv.size())
        usage(argv[0]);
    else if (1 == sv.size() && "-" == sv[0])
        from_stdin();
    else
        from_args(sv);

    return EXIT_SUCCESS;
}

