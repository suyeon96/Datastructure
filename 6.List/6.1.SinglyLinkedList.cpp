/*
 * 6.1
 * 단일 연결리스트 구현
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
    Node<T>* head;
    int size = 0;

public:
    SinglyLinkedList(){
        head = nullptr;
    }
    ~SinglyLinkedList(){}

    void addNode(T data){       // 노드 추가하기 (마지막)
        Node<T>* node = new Node<T>(data, nullptr);

        if(isEmpty()){      // 비어있는 경우 head에 node 추가
            head = node;
        }else{              // 아닌 경우 마지막 node를 찾아서 해당 node의 next에 새로운 node를 연결
            Node<T>* prevNode = head;
            for(int i=0; i<size-1; i++) {
                prevNode = prevNode->getNext();
            }
            prevNode->setNext(node);
        }

        size++;
    }

    void addNode(T data, int idx){  // 노드 추가하기 (index지정)
        if(idx < 0 || idx > size){
            cout << "index error" << endl;
            return;
        }

        Node<T>* node = new Node<T>(data, nullptr);

        if(idx==0){     // 0번째 index에 추가하는 경우
            node->setNext(head);        // 새로운 node의 next에 기존 head node를 연결 (비어있는 경우 nullptr로 들어감)
            head = node;                // 0번째 index가 바꼈기 때문에 head를 바꾸어줌
        }else{          // 아닌경우
            Node<T>* prevNode = head;
            for(int i=0; i<idx-1; i++) {
                prevNode = prevNode->getNext();     // index-1번째 node를 찾은 후
            }
            node->setNext(prevNode->getNext());     // 새로운 node의 next에 이전 node의 next를 대입.
            prevNode->setNext(node);                // 이전 node의 next에는 새로운 node를 연결
        }

        size++;
    }

    void removeNode(int idx){  // 노드 삭제 (index 지정)
        if(isEmpty()){
            cout << "List is Empty" << endl;
            return;
        }
        if(idx < 0 || idx > size){
            cout << "index error" << endl;
            return;
        }

        if(idx==0){     // 0번째 index를 지우는 경우 head를 다음노드로 바꿔줌
            Node<T>* tmpNode = head;
            head = tmpNode->getNext();
            delete tmpNode;
        }else{          // 아닌경우
            Node<T>* prevNode = head;
            for(int i=0; i<idx-1; i++) {
                prevNode = prevNode->getNext();     // index-1번째 node를 찾은 후
            }
            Node<T>* tmpNode = prevNode->getNext();
            prevNode->setNext(tmpNode->getNext());  // 해당 node의 next를 삭제할 node의 next로 바꿔줌
            delete tmpNode;
        }

        size--;
    }

    void display(){     // List 출력
        if(isEmpty()){
            cout << "List is Empty" << endl;
            return;
        }

        Node<T>* tmpNode = head;
        while(tmpNode){
            cout << "[" << tmpNode->getData() << "]";
            tmpNode = tmpNode->getNext();
        }
        cout << endl;
    }

    bool isEmpty(){
        return size==0 ? true : false;
    }
};

int main(){
    SinglyLinkedList<int> list;

    cout << "===== addNode x3 =====" << endl;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.display();

    cout << "===== addNode '4' at index2 =====" << endl;
    list.addNode(4, 2);
    list.display();

    cout << "===== deleteNode at index1 =====" << endl;
    list.removeNode(1);
    list.display();

    return 0;
}