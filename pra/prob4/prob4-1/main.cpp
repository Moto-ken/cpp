
#include <iostream>
#include "number.h"
 
using namespace std;
 
int main(){
    Number* pN;
    pN = new Number();
    pN->set_numbers(1, 2);
    cout << pN->get_add() << endl;
    delete pN;
    return 0;
}