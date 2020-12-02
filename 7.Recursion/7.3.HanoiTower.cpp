/*
 * 7.3
 * 하노이 탑 구현
 */
#include <iostream>
using namespace std;

void hanoi(int n, char from, char tmp, char to){
    if(n==1){
        cout << n << ": " << from << " -> " << to << endl;
    }else{
        hanoi(n-1, from, to, tmp);                          // A의 맨 밑을 제외한 나머지 원판들을 B로 옮김
        cout << n << ": " << from << " -> " << to << endl;  // A에 남은 한 개의 원판(맨 밑)을 C로 옮김
        hanoi(n-1, tmp, from, to);                          // B의 원판들을 C로 옮김
    }
}

int main(){
    hanoi(4, 'A', 'B', 'C');
    return 0;
}