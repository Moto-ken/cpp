
#include "data.h"

void Cdata::init(void)
{
    number = 0;
    comment = "";
}

void Cdata::set_Comment(string a)
{
    comment = a;
}

void Cdata::set_Number(int a)
{
    number = a;
}

int Cdata::get_Number(void)
{
    return (number);
}

string Cdata::get_Comment(void)
{
    return (comment);
}
