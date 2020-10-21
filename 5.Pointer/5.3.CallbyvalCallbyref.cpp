/*
 * 5.3
 * Call by Value vs Call by Reference
 */
#include <iostream>
using namespace std;

void callByVal(int a){
    a = 20;
}

void callByRef(int* b){
    *b = 20;
}

int main()
{
    int a = 10;
    int b = 10;

    callByVal(a);
    callByRef(&b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}