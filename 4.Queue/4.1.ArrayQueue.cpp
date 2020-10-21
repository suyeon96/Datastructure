/*
 * 4.1
 * Array를 이용하여 Linear Queue 구현
 */
#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 20

class Queue {
private:
    int front;  // 첫번째 요소 앞의 index
    int rear;   // 마지막 요소 index
    int data[MAX_QUEUE_SIZE];

public:
    Queue(){
        front = 0;
        rear = 0;
    }
    ~Queue(){}

    void enqueue(int n){
        if(isFull()){
            cout << "Queue Full Error" << endl;
            exit(1);
        }
        data[++rear] = n;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue Empty Error" << endl;
            exit(1);
        }
        return data[++front];
    }

    int size(){
        return rear - front;
    }

    void display(){
        for(int i=front+1; i<=rear; i++){
            cout << "[" << data[i] << "]";
        }
        cout << endl;
    }

    bool isEmpty(){
        return front == rear;
    }
    bool isFull() {
        return rear == MAX_QUEUE_SIZE - 1;
    }
};

int main() {
    Queue queue;

    cout << "===== enqueue x10 =====" << endl;
    for(int i=0; i<10; i++){
        queue.enqueue(i);
    }
    cout << "size : " << queue.size() << endl;
    queue.display();

    cout << "===== dequeue x3 =====" << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    cout << "size : " << queue.size() << endl;
    queue.display();
}