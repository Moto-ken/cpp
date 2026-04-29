
#include <iostream>
#include "minmax.h"

using namespace std;

int main(void)
{
    Minmax m;
    int a = 4;
    int b = 2;
    int c = 9;

    cout << a << "と" << b << "と" << c << "のうち、最大のものは" << m.max(a, b, c) << endl;
    cout << a << "と" << b << "と" << c << "のうち、最小のものは" << m.min(a, b, c) << endl;
    return (0);
}
