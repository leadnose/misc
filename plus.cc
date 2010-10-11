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
        result += i;
    }

    printf("%d\n", result);
}


static
void from_args(const vector<string>& sv)
{
    vector<int> iv(sv.size());
    transform(sv.begin(), sv.end(), iv.begin(), parse_int);
    int result = accumulate(iv.begin(), iv.end(), 0);
    printf("%d\n", result);
}

extern "C"
int main(int argc, char *argv[])
{
    vector<string> sv(argv + 1, argv + argc);

    if (1 == sv.size() && "-" == sv[0])
        from_stdin();
    else
        from_args(sv);

    exit(EXIT_SUCCESS);
}
