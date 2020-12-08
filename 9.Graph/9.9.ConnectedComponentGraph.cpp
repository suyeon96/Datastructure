/*
 * 9.9
 * 인접 행렬(Adjacency Matrix)과 DFS를 이용한 Connected Component (연결 성분) 탐색 프로그램 구현해보기
 */
#include <iostream>
using namespace std;

#define MAX_VTXS 256    // 최대 정점 개수

class AdjMatGraph{
protected:
    int size;                           // 정점의 개수
    char vertices[MAX_VTXS];            // 정점의 이름
    int adjMat[MAX_VTXS][MAX_VTXS];     // 인접 행렬

public:
    AdjMatGraph(){
        reset();
    }
    ~AdjMatGraph(){}

    char getVertex(int i){
        return vertices[i];
    }
    int getEdge(int i, int j){
        return adjMat[i][j];
    }
    void setEdge(int i, int j, int val){
        adjMat[i][j] = val;
    }

    // 그래프 초기화
    void reset(){
        for(int i=0; i<MAX_VTXS; i++){
            for(int j=0; j<MAX_VTXS; j++){
                setEdge(i, j, 0);
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

        vertices[size++] = name;
    }

    // 간선 삽입 (무방향 그래프)
    void insertEdge(int u, int v){
        setEdge(u, v, 1);       // 가중치 그래프에서는 1이 아닌 가중치 삽입
        setEdge(v, u, 1);       // 방향 그래프에서는 삭제 (<u,v>만 존재)
    }

    // 그래프 정보 출력
    void display(){
        cout << "vertex size : " << size << endl;
        cout << "    ";
        for(int i=0; i<size; i++){
            cout << getVertex(i) << " ";
        }
        cout << endl;

        for(int i=0; i<size; i++){
            cout << getVertex(i) << " : ";
            for(int j=0; j<size; j++){
                cout << getEdge(i, j) << " ";
            }
            cout << endl;
        }
    }

    // 두개의 정점이 연결되어 있는지 검사
    bool isLinked(int u, int v){
        return getEdge(u, v) != 0;
    }

    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size >= MAX_VTXS;
    }
};

// DFS를 이용하여 그래프의 연결성분 탐색
class ConnectedComponentGraph : public AdjMatGraph{
private:
    int labelValue = 0;
    int label[MAX_VTXS];     // component label;

public:
    // 모든 node의 label을 0으로 초기화
    void resetVisited(){
        for(int i=0; i<size; i++){
            label[i] = 0;
        }
    }

    // 깊이우선탐색 (순환)
    void labelDfsRecur(int v){
        label[v] = labelValue;

        for(int n=0; n<size; n++){
            if(isLinked(v, n) && label[n]==0){
                labelDfsRecur(n);
            }
        }
    }

    void findConnectedComponent(){
        cout << "== Connected Component ==" << endl;
        int cnt = 0;        // component 개수
        labelValue = 0;     // labelValue 초기화
        resetVisited();     // label array 초기화

        for(int i=0; i<size; i++){
            if(label[i]==0){        // 방문하지 않은 node의 경우
                labelValue++;       // label 값 증가
                labelDfsRecur(i);
                cnt++;
            }
        }

        cout << "- component 개수 : " << cnt << endl;
        for(int i=1; i<=labelValue; i++){
            cout << "  " << i << " : ";
            for(int j=0; j<size; j++){
                if(label[j]==i){
                    cout << "[" << getVertex(j) << "]";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    // 그래프 모양
    cout << "== Graph Shape ==" << endl;
    cout << "A - C   E - G" << endl;
    cout << "          \\ " << endl;
    cout << "B - D - F   H" << endl;
    cout << endl;

    // 인접 행렬 그래프
    ConnectedComponentGraph graph;

    cout << "== Adjacency Matrix Graph == " << endl;
    // 정점 삽입 (A, B, C, D)
    graph.insertVertex('A');    // 0
    graph.insertVertex('B');    // 1
    graph.insertVertex('C');    // 2
    graph.insertVertex('D');    // 3
    graph.insertVertex('E');    // 4
    graph.insertVertex('F');    // 5
    graph.insertVertex('G');    // 6
    graph.insertVertex('H');    // 7
    // 간선 삽입
    graph.insertEdge(0, 2);     // A->C
    graph.insertEdge(1, 3);     // B->D
    graph.insertEdge(3, 5);     // D->F
    graph.insertEdge(4, 6);     // E->G
    graph.insertEdge(4, 7);     // E->H

    graph.display();

    graph.findConnectedComponent();

    return 0;
}