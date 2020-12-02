/*
 * 6.4
 * Quiz! 6.3.SinglyLinkedList2에 연산 추가하기
 * - void reverse() : 모든 노드의 순서를 반대로 바꾸기
 * - void merge(LinkedList* that) : 다른 리스트 that의 노드정보를 현재 리스트에 병합 (연산 후 that 리스트는 공백 리스트가 되어야 함)
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

    // list의 모든 node 순서를 반대로 바꾸기
    void reverse(){
        Node<T>* tail = getEntry(size()-1);
        for(int i=size()-1; i>0; i--){
            Node<T>* prev = getEntry(i-1);
            getEntry(i)->setNext(prev);
            prev->setNext(nullptr);     // size()에서 무한 Loop를 방지하고자 nullptr 대입
        }
        org.setNext(tail);
    }

    // 현재 list에 다른 list(that) merge
    void merge(SinglyLinkedList<T>* that){
        getEntry(size()-1)->setNext(that->getHead());
        that->org.setNext(nullptr);
    }
};

int main(){
    cout << "===================================" << endl;
    SinglyLinkedList<int> listA;
    listA.insert(0, 10);
    listA.insert(1, 20);
    listA.insert(2, 30);
    listA.insert(3, 40);
    listA.insert(4, 50);
    listA.insert(5, 60);
    cout << "List A : ";
    listA.display();

    cout << "@listA.reverse()!!!!" << endl;
    listA.reverse();
    cout << "List A : ";
    listA.display();

    cout << "===================================" << endl;
    SinglyLinkedList<int> listB;
    listB.insert(0, 100);
    listB.insert(1, 200);
    listB.insert(2, 300);
    cout << "List B : ";
    listB.display();

    cout << "@listA.merge(listB)!!!!" << endl;
    listA.merge(&listB);

    cout << "List A : ";
    listA.display();
    cout << "List B : ";
    listB.display();
    cout << "===================================" << endl;

    return 0;
}