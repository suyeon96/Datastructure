/*
 * 8.5
 * Max Heap을 이용하여 내림차순 힙 정렬 구현
 */
#include <iostream>
using namespace std;

#define MAX_ELEMENT 200      // heap array size

struct Node{
private:
    int key;
public:
    Node(){
        key = 0;
    }
    Node(int _key){
        key = _key;
    }
    ~Node(){}

    // getter/setter
    int getKey(){
        return key;
    }
    void setKey(int _key){
        key = _key;
    }
};

class MaxHeap{
private:
    Node node[MAX_ELEMENT];
    int size;   // heap 요소 개수
public:
    MaxHeap(){
        size = 0;
    }
    ~MaxHeap(){}

    // search node
    Node& getParent(int index){
        return node[index/2];
    }
    Node& getLeftChild(int index){
        return node[index*2];
    }
    Node& getRightChild(int index){
        return node[index*2+1];
    }

    // 삽입
    void insert(int key){
        if(isFull()){
            cout << "Heap is Full" << endl;
            return;
        }

        int index = ++size;     // 힙트리 마지막 노드의 다음 위치에서 시작

        // 힙트리를 거슬러 올라가며 부모 노드와 비교
        while(index != 1 && key > getParent(index).getKey()){
            node[index] = getParent(index);
            index /= 2;
        }

        // 최종 위치에 데이터 삽입
        node[index].setKey(key);
    }

    // 삭제
    int remove(){
        if(isEmpty()){
            cout << "Heap is Empty" << endl;
            exit(EXIT_FAILURE);
        }

        Node itemNode = node[1];         // root node (삭제 대상)
        Node lastNode = node[size--];    // 힙트리의 마지막 노드
        int index = 1;                      // 마지막 노드의 index (root 부터 시작)

        // root 부터 내려가며 자식 노드와 비교
        while(index <= size){
            if(index*2 > size){             // leaf node인 경우 (자식 노드가 없는 경우)
                break;
            }else if(index*2 == size){      // 자식노드가 하나인 경우
                if(lastNode.getKey() < getLeftChild(index).getKey()){
                    node[index] = getLeftChild(index);
                    index *= 2;
                }else{
                    break;
                }
            }else{                          // 자식노드가 두개인 경우
                int leftChildKey = getLeftChild(index).getKey();
                int rightChildKey = getRightChild(index).getKey();

                // 둘 중 key가 더 큰 자식노드와 교환
                if(lastNode.getKey() < leftChildKey || lastNode.getKey() < rightChildKey){
                    node[index] = leftChildKey > rightChildKey ? getLeftChild(index) : getRightChild(index);
                    index = leftChildKey > rightChildKey ? index*2 : index*2+1;
                }else{
                    break;
                }
            }
        }
        node[index] = lastNode;     // 마지막 노드를 최종 위치에 저장
        return itemNode.getKey();  // 삭제 노드의 data 반환
    }

    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == MAX_ELEMENT - 1;
    }

};

// 힙 정렬
void heapSort(int a[], int n){
    MaxHeap heap;

    for(int i=0; i<n; i++){
        heap.insert(a[i]);
    }

    for(int i=0; i<n; i++){
        a[i] = heap.remove();
    }
}


int main(){
    int data[10];

    for(int i=0; i<10; i++){
        data[i] = rand() % 100;     // random data
    }

    cout << "origin data : ";
    for(int i=0; i<10; i++) cout << data[i] << " ";
    cout << endl;

    heapSort(data, sizeof(data)/sizeof(int));
    cout << "sorted data : ";
    for(int i=0; i<10; i++) cout << data[i] << " ";
    cout << endl;


    return 0;
}