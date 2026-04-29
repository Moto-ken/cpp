
#ifndef DATA_H
# define DATA_H

#include <iostream>
#include <string>
 
using namespace std;
 
class Cdata{
    private:
        int     number;
        string  comment;
    public:
        void    init();
        void    set_Number(int a);
        void    set_Comment(string a);
        int     get_Number();
        string  get_Comment();
};

#endif
