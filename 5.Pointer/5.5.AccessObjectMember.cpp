/*
 * 5.5
 * 객체의 멤버에 접근하는 방법
 */
#include <iostream>
using namespace std;

class Test{
public:
    int a;
    int b;
};

int main()
{
    Test T;
    Test* pT = &T;

    T.a = 1;
    pT->b = 2;

    cout << "a : " << pT->a << endl;
    cout << "b : " << T.b << endl;

    return 0;
}