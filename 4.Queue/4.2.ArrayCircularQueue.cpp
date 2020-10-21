/*
 * Array를 이용하여 Circular Queue 구현
 */
#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 10

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
        rear = (rear+1)%MAX_QUEUE_SIZE;   // rear가 max를 넘어가는 경우 다시 0번째 index로 순회
        data[rear] = n;
    }

    int dequeue(){
        if(isEmpty()){
            cout << "Queue Empty Error" << endl;
            exit(1);
        }
        front = (front+1)%MAX_QUEUE_SIZE;   // front가 max를 넘어가는 경우 다시 0번째 index로 순회
        return data[front];
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue Empty Error" << endl;
            exit(1);
        }
        return data[(front+1)%MAX_QUEUE_SIZE];
    }

    int size(){
        return front<=rear ? rear-front : (rear+MAX_QUEUE_SIZE)-front;
    }

    void display(){
        for(int i=front+1; i<=front+size(); i++){
            cout << "[" << data[i%MAX_QUEUE_SIZE] << "]";
        }
        cout << endl;
    }

    // Circular array의 front와 rear 정보를 보기위한 메소드
    void displayDetail(){
        cout << "QUEUE :";
        for(int i=front+1; i<=front+size(); i++){
            cout << "[" << data[i%MAX_QUEUE_SIZE] << "]";
        }
        cout << endl;
        cout << "index :";
        for(int i=front+1; i<=front+size(); i++){
            cout << " " << i%MAX_QUEUE_SIZE << " ";
        }
        cout << endl;
        cout << "front : " << front << ", rear : " << rear << endl;
        cout << endl;
    }

    bool isEmpty(){
        return front == rear;
    }
    bool isFull() {
        return front == (rear+1)%MAX_QUEUE_SIZE;
    }
};

int main() {
    Queue queue;

    cout << "===== enqueue x9 =====" << endl;
    for(int i=0; i<9; i++){
        queue.enqueue(i);
    }
    cout << " size : " << queue.size() << endl;
    queue.displayDetail();

    cout << "===== dequeue x3 ======" << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    cout << " size : " << queue.size() << endl;
    queue.displayDetail();

    cout << "===== enqueue x2 ======" << endl;
    queue.enqueue(9);
    queue.enqueue(10);
    cout << " size : " << queue.size() << endl;
    queue.displayDetail();
}