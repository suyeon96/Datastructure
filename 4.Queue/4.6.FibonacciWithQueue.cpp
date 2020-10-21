/*
 * Queue를 이용하여 피보나치 수열 계산
 */
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> queue;

    int cnt = 7;

    queue.push(0);
    queue.push(1);
    cout << queue.front() << " " << queue.back() << " ";

    for(int i=0; i<cnt-1; i++){
        int num1 = queue.front();
        queue.pop();
        int num2 = queue.front();
        queue.push(num1+num2);

        cout << queue.back() << " ";
    }

    cout << '\n' << "fibo(" << cnt << ") : " << queue.back() << endl;
}