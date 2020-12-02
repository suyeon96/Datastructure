/*
 * 9.5
 * 인접 행렬(Adjacency Matrix)를 이용한 Graph의 너비우선탐색(BFS) 구현
 */
#include <iostream>
#include <queue>
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

// BFS 탐색 기능이 추가된 그래프
class SearchAdjMatGraph : public AdjMatGraph{
private:
    bool visited[MAX_VTXS];     // 방문 기록

public:
    // 모든 정점의 방문기록을 false로 초기화
    void resetVisited(){
        for(int i=0; i<size; i++){
            visited[i] = false;
        }
    }

    // 너비우선탐색 (큐 이용)
    void bfs(int v){
        resetVisited();

        visited[v] = true;      // 현재 vertex 방문처리
        cout << getVertex(v) << " ";

        queue<int> queue;
        queue.push(v);          // 시작 vertex enqueue

        while(!queue.empty()){
            v = queue.front();
            queue.pop();        // v = queue.dequeue()

            // 인접 정점 탐색
            for(int n=0; n<size; n++){
                if(isLinked(v, n) && visited[n]==false){
                    cout << getVertex(n) << " ";
                    visited[n] = true;  // 방문 처리
                    queue.push(n);
                }
            }
        }

    }
};

int main(){
    SearchAdjMatGraph graph;

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
    graph.insertEdge(0, 1);     // A->B
    graph.insertEdge(0, 2);     // A->C
    graph.insertEdge(1, 3);     // B->D
    graph.insertEdge(2, 3);     // C->D
    graph.insertEdge(2, 4);     // C->E
    graph.insertEdge(3, 5);     // D->F
    graph.insertEdge(4, 6);     // E->G
    graph.insertEdge(4, 7);     // E->H
    graph.insertEdge(6, 7);     // G->H

    cout << "== Display Graph == " << endl;
    graph.display();

    cout << "-BFS => ";
    graph.bfs(0);

    return 0;
}