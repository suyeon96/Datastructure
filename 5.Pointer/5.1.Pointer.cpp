/*
 * 5.1
 * 포인터 기본
 */
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* p = &a;

    cout << "a : " << a << endl;
    cout << "&a : " << &a << endl;
    cout << "p : " << p << endl;
    cout << "*p : " << *p << endl;
    cout << "&p : " << &p << endl;
}