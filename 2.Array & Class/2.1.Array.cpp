/*
 * 2.1
 * 1차원, 2차원 배열 선언 및 크기 구하기
 */
#include <iostream>
using namespace std;

int main() {
    // 1차원 배열
    int arr1[5] = {1, 2, 3, 4, 5};

    // 2차원 배열
    int arr2[2][3] = {{1, 2, 3},
                      {4, 5, 6}};

    // 배열의 크기
    cout << sizeof(arr1)/sizeof(arr1[0]) << endl;    // 5
    cout << sizeof(arr2)/sizeof(int) << endl;        // 6

    return 0;
}