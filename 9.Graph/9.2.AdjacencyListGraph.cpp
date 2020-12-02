/*
 * 9.2
 * 인접 리스트(Adjacency List)를 이용한 Graph 구현 (무방향 그래프)
 */
#include <iostream>
using namespace std;

#define MAX_VTXS 256    // 최대 정점 개수

struct Node{
private:
    int id;         // vertex id
    Node* link;     // next node's pointer

public:
    Node(int _id, Node* _link){
        id = _id;
        link = _link;
    }
    ~Node(){};

    // getter/setter
    int getId(){
        return id;
    }
    void setId(int _id){
        id = _id;
    }
    Node* getLink(){
        return link;
    }
    void setLink(Node* _link){
        link = _link;
    }
};

class AdjListGraph{
private:
    int size;                   // 정점의 개수
    char vertices[MAX_VTXS];    // 정점의 이름
    Node* adjList[MAX_VTXS];    // 인접 리스트

public:
    AdjListGraph(){
        size = 0;
    }
    ~AdjListGraph(){}

    char getVertex(int i){
        return vertices[i];
    }

    // 그래프 초기화
    void reset(){
        for(int i=0; i<size; i++){
            if(adjList[i] != NULL){
                delete adjList[i];
            }
        }
        size = 0;
    }

    // 정점 삽입
    void insertVertex(char name){
        if(isFull()){
            cout << "Graph vertex full error" << endl;
            return;
        }

        vertices[size] = name;
        adjList[size++] = NULL;
    }

    // 간선 삽입 (무방향 그래프)
    void insertEdge(int u, int v){
        // 인접리스트에 추가
        adjList[u] = new Node(v, adjList[u]);   // 새로운 노드로 head pointer가 바뀜 (새로운 node는 기존의 head pointer를 link로 함)
        adjList[v] = new Node(u, adjList[v]);   // 방향 그래프에서는 삭제 (<u,v>만 존재)
    }

    // 그래프 정보 출력
    void display(){
        cout << "vertex size : " << size << endl;
        for(int i=0; i<size; i++){
            cout << getVertex(i) << " : ";
            Node* head = adjList[i];
            while(head != NULL){
                cout << getVertex(head->getId()) << " ";
                head = head->getLink();
            }
            cout << endl;
        }
    }

    // 'v'번째 정점의 인접 정점 리스트 반환
    Node* adjacent(int v){
        return adjList[v];
    }

    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size >= MAX_VTXS;
    }
};


int main(){
    AdjListGraph graph;

    // 정점 삽입 (A, B, C, D)
    graph.insertVertex('A');    // 0
    graph.insertVertex('B');    // 1
    graph.insertVertex('C');    // 2
    graph.insertVertex('D');    // 3

    // 간선 삽입
    graph.insertEdge(0, 1);     // A->B
    graph.insertEdge(0, 2);     // A->C
    graph.insertEdge(0, 3);     // A->D
    graph.insertEdge(2, 3);     // C->D

    graph.display();

    return 0;
}