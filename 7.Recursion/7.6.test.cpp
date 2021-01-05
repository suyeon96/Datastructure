/*
 * 7.5
 * 순환적인 방법으로 피보나치수열을 호출하였을 때 함수가 중복되어 호출되는 것을
 * 확인할 수 있도록 각 함수의 매개변수별 호출 빈도를 측정해 출력하라.
 */
#include <iostream>
using namespace std;

int fibo(int n, int* arr){
    arr[n]++;
    if(n==0) return 0;
    if(n==1) return 1;
    else return (fibo(n-1, arr) + fibo(n-2, arr));
}

int main(){
    int n = 10;
    int* arr = new int[n+1];
    for(int i=0; i<n+1; i++){
        arr[i] = 0;
    }

    fibo(n, arr);

    for(int i=n; i>=0; i--){
        cout << "fibo(" << i << ") = " << arr[i] << "번" << endl;
    }

    delete[] arr;
    return 0;
}