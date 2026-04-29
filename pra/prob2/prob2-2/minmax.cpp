
#include "minmax.h"
#include <iostream>
#include <algorithm>

// int Minmax::max(int n1, int n2, int n3)
// {
//     return std::max({n1, n2, n3});
// }

// int Minmax::min(int n1, int n2, int n3)
// {
//     return std::min({n1, n2, n3});
// }

int Minmax::min(int n1, int n2, int n3)
{
    // std::cout << "this is minfunk stdout" << -n1 << std::endl;
    return (-max(-n1, -n2, -n3));
}

int Minmax::max(int n1, int n2, int n3)
{
    int tmp = 0;

    if (n1 > n2)
        tmp = n1;
    else 
        tmp = n2;
    
    if (tmp > n3)
        return (tmp);
    else
        return (n3);
}

