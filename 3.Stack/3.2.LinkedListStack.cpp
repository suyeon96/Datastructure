/*
 * 3.2
 * LinkedList를 이용하여 Stack 구현
 */
#include <iostream>
using namespace std;

// Node Struct
struct Node {
    int data;
    Node* link; // 이전 Node를 가리키는 pointer

public:
    Node(){
        link = NULL;
        data = 0;
    }
    Node(int n, Node* preNode = nullptr){
        data = n;
        link = preNode;
    }
    ~Node(){}
};

// Stack Class
class Stack {
private:
    Node* top;      // Stack의 top을 가리키는 Node pointer
    int dataSize;   // Stack에 저장된 데이터 size

public:
    Stack(){
        top = nullptr;
        dataSize = 0;
    }
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
        delete top;
    }

    //새로운 node를 생성 후 top을 새로운 node로 변경
    //새로운 node의 link에는 이전node(top이였던)가 들어감
    void push(int n){
        Node* node = new Node(n, top);
        top = node;
        dataSize++;
    }

    //stck이 비어있는 경우 error occurred
    //그렇지 않다면, 우선 top node의 데이터를 임시 변수 'data'에 담아놓음
    //top을 이전 node로 변경한 다음 삭제된 node(top이였던)는 delete 처리 (메모리자원을위해)
    //아까 담아놓은 'data'를 반환
    int pop(){
        if(isEmpty()){
            cout << "Stack Empry Error" << endl;
            exit(EXIT_FAILURE);
        }else{
            int data = top->data;
            Node* node = top;
            top = top->link;
            delete node;
            dataSize--;
            return data;
        }
    }

    // stack의 모든 data 출력
    void display(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
        }else{
            Node* node = top;
            while(node){
                cout << "[" << node->data << "]";
                node = node->link;
            }
            cout << endl;
        }
    }

    // stack size 반환
    int size(){
        return dataSize;
    }

    bool isEmpty(){
        return dataSize == 0;
    }
};

int main() {
    Stack stack;

    cout << "===== push x10 =====" << endl;
    for(int i=0; i<10; i++){
        stack.push(i);
    }
    cout << "size : " << stack.size() << endl;
    stack.display();

    cout << "===== pop x3 =====" << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout << "size : " << stack.size() << endl;
    stack.display();
}