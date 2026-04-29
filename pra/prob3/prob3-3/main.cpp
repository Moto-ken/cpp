
#include "calculation.h"

using namespace std;

int main(void)
{
    Calculation c;

    c.set_number1(8);
    c.set_number2(9);
    cout << c.get_number1() << " + " << c.get_number2() << " = " << c.add() << endl;
    cout << c.get_number1() << " - " << c.get_number2() << " = " << c.sub() << endl;
    return (0);
}
