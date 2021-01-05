/*
 * 7.3
 * 피보나치 수열 구현 (반복 & 순환)
 */
#include <iostream>
using namespace std;

double iterFibo(int n){
    if(n<2) return n;
    else{
        int tmp, current=1, last=0;
        for(int i=2; i<=n; i++){
            tmp = current;
            current += last;
            last = tmp;
        }
        return current;
    }
}

double recurFibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    else return (recurFibo(n-1) + recurFibo(n-2));
}

int main(){
    int n = 6;
    cout << " Iter : " << iterFibo(n) << endl;
    cout << " Recur : " << recurFibo(n) << endl;

    return 0;
}