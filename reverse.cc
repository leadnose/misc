#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <string>

using namespace ::std;

static
void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s\n", progname);
}

int main(int argc, char *argv[])
{
    if (1 != argc) {

        usage(argv[0]);
        exit(EXIT_FAILURE);

    } else {

        vector<string> lines;

        for (;;) {
            string s;
            lines.push_back(s);
            getline(cin, *lines.rbegin());
            if (cin.eof())
                break;
        }

        for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
            cout << *it << '\n'; 
        }


        cout.flush();

        exit(EXIT_SUCCESS);
    }
}
