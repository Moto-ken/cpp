
#include "data.h"
 
using namespace std;
 
int main()
{
    Cdata d;
    d.init();   //  パラメータを初期化
    d.set_Number(100);
    d.set_Comment("Programming C++");
    cout << "number = " << d.get_Number() << " comment = " << d.get_Comment() << endl;
    return 0;
}
