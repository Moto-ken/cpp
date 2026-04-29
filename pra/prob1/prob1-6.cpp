
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a;
    string b;

    cout << "姓を入力:";
    cin >> a;
    cout << "命を入力:";
    cin >> b;
    cout << "名前は「" << a + b << "」です。" << endl;

    return (0);
}

