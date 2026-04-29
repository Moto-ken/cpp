
#include "calculation.h"

void    Calculation::set_number1(int n)
{
    m_number1 = n;
}

void    Calculation::set_number2(int n)
{
    m_number2 = n;
}

int     Calculation::get_number1(void)
{
    return (m_number1);
}

int     Calculation::get_number2(void)
{
    return (m_number2);
}

int     Calculation::add(void)
{
    return (m_number1 + m_number2);
}

int     Calculation::sub(void)
{
    return (m_number1 - m_number2);
}
