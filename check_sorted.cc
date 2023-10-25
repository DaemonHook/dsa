#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int cur;
    int t;
    cin >> cur;
    while (cin >> t) {
        if (t >= cur) {
            cur = t;
        } else {
            cout << "Wrong!" << endl;
            exit(0);
        }
    }
    cout << "Right!" << endl;
    return 0;
}