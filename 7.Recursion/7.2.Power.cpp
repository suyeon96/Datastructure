/*
 * 7.2
 * 거듭제곱 구현 (반복 & 순환)
 */
#include <iostream>
using namespace std;

double iterPower(double x, int n){
    double r = 1.0;
    for(int i=0; i<n; i++){
        r = r * x;
    }
    return r;
}

double recurPower(double x, int n){
    if(n==0) return 1.0;
    else if((n%2)==0)           // n이 짝수인 경우
        return recurPower(x*x, n/2);
    else                        // n이 홀수인 경우
        return x * recurPower(x*x, (n-1)/2);
}

int main(){
    double x = 2.0;
    int n = 10;
    cout << " Iter : " << iterPower(x, n) << endl;
    cout << " Recur : " << recurPower(x, n) << endl;

    return 0;
}