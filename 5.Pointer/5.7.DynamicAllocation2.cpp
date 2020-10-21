/*
 * 5.7
 * 동적메모리 할당 - new & delete
 */
#include <iostream>
using namespace std;

int main() {
    int size = 10;

    // 할당
    int *pData = new int;
    int *array = new int[size];

    // 소멸
    delete pData;
    delete[] array;

    return 0;
}