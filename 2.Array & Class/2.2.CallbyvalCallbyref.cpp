/*
 * 2.2
 * 함수의 매개변수로서의 배열 (Call by Value vs Call by Reference)
 */
#include <iostream>
using namespace std;

void callByVal(int a, int b){
    a = 1;
    b = 1;
}

void callByRef(int a[], int *b){
    a[0] = 1;
    *b = 1;
}

int main() {

    int arrA[] = {0, 0};
    int arrB[] = {0, 0};

    callByVal(arrA[0], arrB[0]);
    cout << "arrA[0] : " << arrA[0] << ", arrB[0] : " << arrB[0] << endl;

    callByRef(arrA, arrB);
    cout << "arrA[0] : " << arrA[0] << ", arrB[0] : " << arrB[0] << endl;

    return 0;
}