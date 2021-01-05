/*
 * 7.1
 * 팩토리얼 구현 (순환)
 */
#include <iostream>
using namespace std;

int factorial(int n){
    if(n==1) return 1;
    else return (n * factorial(n-1));
}

int main(){
    cout << factorial(5) << endl;

    return 0;
}