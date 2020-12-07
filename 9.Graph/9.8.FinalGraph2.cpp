/*
 * 9.8
 * Graph 최종2 - txt파일 load하여 그래프 생성
 */
#include <iostream>
#include <queue>
using namespace std;

#define MAX_VTXS 256    // 최대 정점 개수

/*
 * 인접 행렬 그래프
 */
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

    // 파일 입력받아서 그래프 생성
    void loadFile(char *filename){
        FILE *fp = fopen(filename, "r");
        if(fp != NULL){
            int n;
            fscanf(fp, "%d", &n);
            for(int i=0; i<n; i++){
                char str[80];
                fscanf(fp, "%s", str);              // 정점의 이름
                insertVertex(str[0]);           // 정점 삽입
                for(int j=0; j<n; j++){
                    int val;
                    fscanf(fp, "%d", &val);         // 간선 정보
                    if(val != 0){
                        insertEdge(i, j);           // 간선 삽입
                    }
                }
            }
            fclose(fp);
        }
    }
};


/*
 * 인접 리스트 그래프
 */
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
protected:
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

    // 두개의 정점이 연결되어 있는지 검사
    bool isLinked(int u, int v){
        for(Node *p=adjList[u]; p!= NULL; p=p->getLink()){
            if(p->getId()==v){
                return true;
            }
        }
        return false;
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

    // 간선 삽입 (방향 그래프) - 인접 행렬 형태의 그래프를 load할 때 사용
    void insertEdge2(int u, int v){
        adjList[u] = new Node(v, adjList[u]);
    }
    // 파일 입력받아서 그래프 생성
    void loadFile(char *filename){
        FILE *fp = fopen(filename, "r");
        if(fp != NULL){
            int n;
            fscanf(fp, "%d", &n);
            for(int i=0; i<n; i++){
                char str[80];
                fscanf(fp, "%s", str);              // 정점의 이름
                insertVertex(str[0]);           // 정점 삽입
                for(int j=0; j<n; j++){
                    int val;
                    fscanf(fp, "%d", &val);         // 간선 정보
                    if(val != 0){
                        insertEdge2(i, j);           // 간선 삽입 (인접 행렬 형태의 그래프를 읽으므로 inesrtEdge2())
                    }
                }
            }
            fclose(fp);
        }
    }
};

/*
 * 탐색 기능이 추가된 그래프 (인접 행렬)
 */
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

    // 깊이우선탐색 (순환)
    void dfs(int v){
        resetVisited();
        dfsRecur(v);
    }
    void dfsRecur(int v){
        visited[v] = true;      // 현재 vertex 방문처리
        cout << getVertex(v) << " ";

        for(int n=0; n<size; n++){
            if(isLinked(v, n) && visited[n]==false){
                dfsRecur(n);
            }
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

/*
 * 탐색 기능이 추가된 그래프 (인접 리스트)
 */
class SearchAdjListGraph : public AdjListGraph{
private:
    bool visited[MAX_VTXS];     // 방문 기록

public:
    // 모든 정점의 방문기록을 false로 초기화
    void resetVisited(){
        for(int i=0; i<size; i++){
            visited[i] = false;
        }
    }

    // 깊이우선탐색 (순환)
    void dfs(int v){
        resetVisited();
        dfsRecur(v);
    }
    void dfsRecur(int v){
        visited[v] = true;      // 현재 vertex 방문처리
        cout << getVertex(v) << " ";

        // v 정점의 인접리스트를 모두 방문하며 탐색
        for(Node *p=adjList[v]; p!=NULL; p=p->getLink()){
            if(visited[p->getId()] == false){
                dfsRecur(p->getId());
            }
        }
    }

    // 너비우선탐색 (큐 사용)
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
            for(Node *n=adjList[v]; n!=NULL; n=n->getLink()){
                int nId = n->getId();       // 인접 노드의 정점 id
                if(!visited[nId]){
                    cout << getVertex(nId) << " ";
                    visited[nId] = true;  // 방문 처리
                    queue.push(nId);
                }
            }
        }
    }
};

int main(){
    // 그래프 모양
    cout << "== Graph Shape ==" << endl;
    cout << "A - C - E - G" << endl;
    cout << "|   |     \\ " << endl;
    cout << "B - D - F   H" << endl;
    cout << endl;

    // 인접 행렬 그래프
    SearchAdjMatGraph matGraph;

    matGraph.loadFile((char*)"9.Graph/TestGraph.txt");
    cout << "== Adjacency Matrix Graph == " << endl;
    matGraph.display();

    cout << "-DFS => ";
    matGraph.dfs(0);
    cout << '\n' << "-BFS => ";
    matGraph.bfs(0);
    cout << '\n' << endl;

    // 인접 리스트 그래프
    SearchAdjListGraph listGraph;

    listGraph.loadFile((char*)"9.Graph/TestGraph.txt");
    cout << "== Adjacency List Graph == " << endl;
    listGraph.display();

    cout << "-DFS => ";
    listGraph.dfs(0);
    cout << '\n' << "-BFS => ";
    listGraph.bfs(0);

    return 0;
}