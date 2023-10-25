#include <iostream>
#include <limits.h>
#include <random>
#include <string.h>

using namespace std;

random_device rd;
default_random_engine eng(rd());

uniform_int_distribution<int> distr(0, INT_MAX);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "argc must == 2\n";
        exit(1);
    }
    int n;
    n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        cout << distr(eng) << ' ';
    }
    return 0;
}