/*
 * 5.6
 * 정적배열 vs 동적배열
 */
#include <iostream>
using namespace std;

class Test{
public:
    int a;
    int b;
};

int main() {
    int n = 10;

    // 정적 배열
    int arr1[10];   // 가능
    //int arr1[n];  // 불가능

    // 동적 배열
    int* arr2 = new int[n];    // arr2 포인터 변수는 stack에 할당되며, arr 배열은 heap에 할당됨

    return 0;
}