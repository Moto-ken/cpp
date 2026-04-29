
#include "function.h"
#include <iostream>

using namespace std;

int main(void)
{
    int m = 3;
    int n = 1;

    cout << m << "と" << n << "のうち、最大のものは" << Function::max(m, n) << endl;
    cout << m << "と" << n << "のうち、最小のものは" << Function::min(m, n) << endl;
    return (0);
}
