
#include "number.h"

Number::Number() : a(0), b(0)
{
}

Number::~Number()
{
}

void Number::set_numbers(int n1, int n2)
{
    a = n1;
    b = n2;
}

int Number::get_add()
{
    return (a + b);
}
