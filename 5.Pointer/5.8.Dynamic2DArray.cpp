/*
 * 5.8
 * 2차원 배열의 동적할당
 */
#include <iostream>
using namespace std;

// int형 2차원 배열 동적 할당
int** alloc2DArr (int rows, int cols){
    if(rows <= 0 || cols <= 0) return NULL;
    int** mat = new int* [rows];
    for (int i=0 ; i<rows ; i++ )
        mat[i] = new int[cols];
    return mat;
}

// int형 2차원 배열 동적 해제
void free2DArr ( int** mat, int rows, int cols=0){
    if(mat != NULL){
        for(int i=0 ; i<rows ; i++)
            delete[] mat[i];
        delete[] mat;
    }
}


int main() {

    int **mat;
    int rows, cols;
    cin >> rows >> cols;

    // mat 할당
    mat = alloc2DArr(rows, cols);

    // mat[][] 랜덤 입력
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            mat[i][j] = rand()%100;
        }
    }

    // mat 출력
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // mat 해제
    free2DArr(mat, rows, cols);

    return 0;
}