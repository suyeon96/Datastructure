/*
 * 6.3
 * 단일 연결리스트 구현 (head node 사용)
 */
#include <iostream>
using namespace std;

// Node
template <typename T>
struct Node {
private:
    T data;
    Node<T>* next = nullptr;
public:
    Node(){
        data = T();
        next = nullptr;
    }
    Node(T d, Node<T>* pNode){
        data = d;
        next = pNode;
    }
    ~Node(){}

    Node<T>* getNext() {
        return next;
    }
    void setNext(Node<T>* pNode){
        next = pNode;
    }
    T getData(){
        return data;
    }
};

template <typename T>
class SinglyLinkedList {
private:
    Node<T> org;  // head node

public:
    SinglyLinkedList(){}
    ~SinglyLinkedList(){}

    // first node 반환 (list의 head pointer)
    Node<T>* getHead(){
        return org.getNext();
    }

    // idx번째 항목 반환
    Node<T>* getEntry(int idx){
        if(idx<-1 || idx>size()){
            cout << "index error" << endl;
            exit(EXIT_FAILURE);
        }

        Node<T>* node = &org;

        // head node부터 idx번 반복해서 next node를 찾아감
        for(int i=-1; i<idx; i++){
            node = node->getNext();
        }
        return node;
    }

    // list의 idx번째에 data 삽입
    void insert(int idx, T data){
        Node<T>* prev = getEntry(idx-1);                // idx번째 node의 이전 node

        Node<T>* node = new Node<T>(data, prev->getNext()); // 새로운 node의 next에 prev의 next를 대입
        prev->setNext(node);                                // prev의 next에는 새로운 node의 주소 대입
    }

    // list의 idx번째 요소 삭제 및 반환
    T remove(int idx){
        if(isEmpty()){
            cout << "List is Empty" << endl;
            exit(EXIT_FAILURE);
        }
        Node<T>* node = getEntry(idx);          // 삭제할 node
        T data = node->getData();               // 삭제할 node의 data

        Node<T>* prev = getEntry(idx-1);    // idx번째 node의 이전 node
        prev->setNext(node->getNext());         // prev의 next에 삭제할 node의 next 대입
        delete node;

        return data;
    }

    // list의 idx번째 요소를 data로 변경
    void replace(int idx, T data){
        Node<T>* prev = getEntry(idx-1);    // 삭제될 node의 이전 node

        Node<T>* node = new Node<T>(data, prev->getNext()->getNext());  // 새로운 node
        delete prev->getNext();
        prev->setNext(node);
    }

    // list 출력
    void display(){
        if(isEmpty()){
            cout << "List is Empty" << endl;
            return;
        }

        for(Node<T> *p = getHead(); p != nullptr; p=p->getNext()){
            cout << "[" << p->getData() << "]";
        }
        cout << endl;
    }

    int size(){
        int cnt = 0;
        for(Node<T> *p = getHead(); p != nullptr; p=p->getNext()){
            cnt++;
        }
        return cnt;
    }

    bool isEmpty(){
        return size()==0 ? true : false;
    }

    void clear(){
        while(!isEmpty()){
            remove(0);
        }
    }
};

int main(){
//    SinglyLinkedList<char> list;
//
//    cout << "===== insert x3 =====" << endl;
//    list.insert(0, 'a');
//    list.insert(1, 'b');
//    list.insert(2, 'c');
//    list.display();
//
//    cout << "===== insert 'd' at index2 =====" << endl;
//    list.insert(2, 'd');
//    list.display();
//
//    cout << "===== remove index1 =====" << endl;
//    list.remove(1);
//    list.display();

    SinglyLinkedList<int> list;
    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(1, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();
    list.remove(2);
    list.remove(list.size()-1);
    list.remove(0);
    list.replace(1, 90);
    list.display();
    list.clear();
    list.display();

    return 0;
}