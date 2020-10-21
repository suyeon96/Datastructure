/*
 * 6.3
 * LinkedList를 이용하여 Queue 구현
 */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link; // 다음 Node를 가리키는 pointer

public:
    Node(){
        link = nullptr;
        data = 0;
    }
    Node(int n, Node* nextNode = nullptr){
        data = n;
        link = nextNode;
    }
    ~Node(){}

    void setLink(Node* nextNode){
        link = nextNode;
    }
};

// Queue Class
class Queue {
private:
    Node* front;    // Queue의 front를 가리키는 Node pointer
    Node* rear;     // Queue의 rear를 가리키는 Node pointer
    int dataSize;   // Queue에 저장된 데이터 size

public:
    Queue(){
        front = nullptr;
        rear = nullptr;
        dataSize = 0;
    }
    ~Queue(){
        while(!isEmpty()){
            dequeue(); //deleteRear();
        }
    }

    //새로운 node를 생성 후 rear를 새로운 node로 변경
    void enqueue(int n){
        Node* node = new Node(n, nullptr);
        if(isEmpty()){
            front = node;
        }else{
            rear->setLink(node);
        }
        rear = node;
        dataSize++;
    }

    //queue가 비어있는 경우 error occurred
    //그렇지 않다면, 우선 front node의 데이터를 임시 변수 'data'에 담아놓음
    //front를 next node로 변경한 다음, 삭제된 node(front였던)는 delete 처리 (메모리자원을위해)
    //아까 담아놓은 'data'를 반환
    int dequeue(){
        if(isEmpty()){
            cout << "Queue Empty Error" << endl;
            exit(EXIT_FAILURE);
        }else{
            int data = front->data;
            Node* node = front;
            front = front->link;
            delete node;
            dataSize--;
            return data;
        }
    }

    // queue의 모든 data 출력
    void display(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return;
        }else{
            Node* node = front;
            while(node){
                cout << "[" << node->data << "]";
                node = node->link;
            }
            cout << endl;
        }
    }

    // queue size 반환
    int size(){
        return dataSize;
    }

    bool isEmpty(){
        return dataSize == 0;
    }
};

int main() {
    Queue queue;

    cout << "===== enqueue x3 =====" << endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << " size : " << queue.size() << endl;
    queue.display();

    cout << "===== dequeue x2 ======" << endl;
    queue.dequeue();
    queue.dequeue();
    cout << " size : " << queue.size() << endl;
    queue.display();

    cout << "===== enqueue x1 ======" << endl;
    queue.enqueue(4);
    cout << " size : " << queue.size() << endl;
    queue.display();
}