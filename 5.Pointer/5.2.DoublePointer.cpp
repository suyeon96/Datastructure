/*
 * 5.2
 * 다중 포인터
 */
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p1 = &a;
    int** p2 = &p1;
    int*** p3 = &p2;

    cout << "a : " << a << endl;
    cout << "&a : " << &a << '\n' << endl;

    cout << "p1 : " << p1 << endl;
    cout << "*p1 : " << *p1 << endl;
    cout << "&p1 : " << &p1 << '\n' <<  endl;

    cout << "p2 : " << p2 << endl;
    cout << "*p2 : " << *p2 << endl;
    cout << "**p2 : " << **p2 << endl;
    cout << "&p2 : " << &p2 << '\n' <<  endl;

    cout << "p3 : " << p3 << endl;
    cout << "*p3 : " << *p3 << endl;
    cout << "**p3 : " << **p3 << endl;
    cout << "***p3 : " << ***p3 << endl;
    cout << "&p3 : " << &p3 << endl;
}