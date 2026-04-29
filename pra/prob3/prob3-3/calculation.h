
#ifndef CALCULATION_H
# define CALCULATION_H

#include <iostream>

class Calculation{
    private:
        int m_number1;
        int m_number2;
    public:
        void    set_number1(int n);
        void    set_number2(int n);
        int     get_number1(void);
        int     get_number2(void);
        int     add(void);
        int     sub();
};

#endif
