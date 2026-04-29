
#include "car.h"
#include "ambulance.h"
 
int main() {
    CCar c;
    c.supply(10);   //  燃料補給
    c.move();   //  移動
    c.move();   //  移動
    CAmbulance a;
    a.supply(10);
    a.move();
    a.sevePeople();
    return 0;
}
