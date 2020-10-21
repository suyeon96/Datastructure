/*
 * 3.1
 * Array를 이용하여 Stack 구현
 */
#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 20

// Stack Class
class Stack {
private:
    int top;
    int data[MAX_STACK_SIZE];

public:
    Stack(){
        top = -1;
    }
    ~Stack(){}

    void push(int n){
        if(isFull()){
            cout << "Stack Full Error" << endl;
            exit(1);
        }
        data[++top] = n;
    }

    int pop(){
        if(isEmpty()){
            cout << "Stack Empty Error" << endl;
            exit(1);
        }
        return data[top--];
    }

    void size(){
        cout << "size : " << top+1 <<endl;
    }

    void display(){
        for(int i=0; i<=top; i++){
            cout << "[" << data[i] << "]";
        }
        cout << endl;
    }

    bool isEmpty(){
        return top == -1;
    }
    bool isFull() {
        return top == MAX_STACK_SIZE - 1;
    }
};

int main() {
    Stack stack;

    cout << "===== push x10 =====" << endl;
    for(int i=0; i<10; i++){
        stack.push(i);
    }
    stack.size();
    stack.display();

    cout << "===== pop x3 =====" << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.size();
    stack.display();
}