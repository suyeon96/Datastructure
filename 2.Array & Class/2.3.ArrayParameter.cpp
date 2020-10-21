/*
 * 2.3
 * 함수의 매개변수로 배열 전
 */
#include <iostream>
using namespace std;

// 1차원 배열
void printArr1(char arr[], int len){
    cout << "===== printArr1 =====" << endl;
    for(int i=0; i<len; i++){
        cout << arr[i];
    }
}

// 2차원 배열
void printArr2(char arr[][5], int col, int row){
    cout << "\n===== printArr2 =====" << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {

    char arr1[5] = {'H','E','L','L','O'};
    char arr2[2][5] = {{'h','e','l','l','o'},
                       {'w','o','r','l','d'}};

    // 1차원 배열
    int len = sizeof(arr1)/sizeof(arr1[0]);
    printArr1(arr1, len);    // 배열의 길이를 함께 전달해야함.

    // 2차원 배열
    int col = sizeof(arr2[0])/sizeof(arr2[0][0]);
    int row = sizeof(arr2)/sizeof(arr2[0]);
    printArr2(arr2, col, row);    // 배열의 가로, 세로 크기를 전달해야함.

    return 0;
}