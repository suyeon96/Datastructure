/*
 * 8.2
 * 이진탐색트리
 */
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
struct Node{
private:
    T data;
    Node* left;
    Node* right;
public:
    Node(T _data, Node* _left, Node* _right){
        data = _data;
        left = _left;
        right = _right;
    }
    ~Node(){}

    // getter/setter
    T getData(){
        return data;
    }
    void setData(T _data){
        data = _data;
    }
    Node* getLeft(){
        return left;
    }
    void setLeft(Node* _left){
        left = _left;
    }
    Node* getRight(){
        return right;
    }
    void setRight(Node* _right){
        right = _right;
    }

    // is leaf node?
    bool isLeaf(){
        return left==nullptr && right==nullptr;
    }

    // Node 멤버함수로 순환탐색 구현 (ㅎㅎ)
    Node* search(T key){
        if(key == data)                         // key == 노드의 data
            return this;
        else if(key < data && left != NULL)     // key < 노드의 data
            return left->search(key);
        else if(key > data && right != NULL)    // key > 노드의 data
            return left->search(key);
        else                                    // 탐색이 실패한 경우
            return NULL;
    }
};

template <typename T>
class BinaryTree{
private:
    Node<T>* root;
public:
    BinaryTree(){
        root = nullptr;
    }
    ~BinaryTree(){}

    // set root node
    void setRoot(Node<T>* _root){
        root = _root;
    }
    // get root node
    Node<T>* getRoot(){
        return root;
    }

    // 전위 순회(Pre-order Traversal)
    void preorder(){
        cout << "Preorder  : [ ";
        preorder(root);
        cout << "]" << endl;
    }
    void preorder(Node<T>* node){
        if(node != NULL){
            cout << node->getData() << " ";
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }

    // 중위 순회(In-order Traversal)
    void inorder(){
        cout << "Inorder   : [ ";
        inorder(root);
        cout << "]" << endl;
    }
    void inorder(Node<T>* node){
        if(node != NULL){
            inorder(node->getLeft());
            cout << node->getData() << " ";
            inorder(node->getRight());
        }
    }

    // 후위 순회(Post-order Traversal)
    void postorder(){
        cout << "Postorder : [ ";
        postorder(root);
        cout << "]" << endl;
    }
    void postorder(Node<T>* node){
        if(node != NULL){
            postorder(node->getLeft());
            postorder(node->getRight());
            cout << node->getData() << " ";
        }
    }

    // 레벨 순회(Level-order Traversal)
    void levelorder(){
        cout << "Levelorder: [ ";
        if(!isEmpty()){
            queue<Node<T>*> q;
            q.push(root);
            while(!q.empty()){
                Node<T>* node = q.front();
                q.pop();
                if(node != NULL){
                    cout << node->getData() << " ";
                    q.push(node->getLeft());
                    q.push(node->getRight());
                }
            }
        }
        cout << "]" << endl;
    }

    // 전체 노드 개수 구하기
    int getCount(){
        return isEmpty() ? 0 : getCount(root);
    }
    int getCount(Node<T>* node){
        if(node == NULL) return 0;
        return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }

    // leaf 노드 개수 구하기
    int getLeafCount(){
        return isEmpty() ? 0 : getLeafCount(root);
    }
    int getLeafCount(Node<T>* node){
        if(node == NULL) return 0;
        if(node->isLeaf()) return 1;
        else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }

    // 트리 높이 구하기
    int getHeight(){
        return isEmpty() ? 0 : getHeight(root);
    }
    int getHeight(Node<T>* node){
        if(node == NULL) return 0;
        int lHeight = getHeight(node->getLeft());   // 왼쪽 서브트리 높이 계산
        int rHeight = getHeight(node->getRight());  // 오른쪽 서브트리 높이 계산
        return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
    }

    bool isEmpty(){
        return root == nullptr;
    }

};

// 이진탐색트리 (이진트리 상속)
template <typename T>
class BinarySearchTree : public BinaryTree<T>{
private:
    // 탐색 (순환)
    Node<T>* searchRecur(Node<T>* node, T key){
        if(node == NULL) return NULL;

        if(key == node->getData()) return node;     // key == root 노드의 data
        else if(key < node->getData()) return searchRecur(node->getLeft(), key);    // key < root 노드의 data
        else if(key > node->getData()) return searchRecur(node->getRight(), key);   // key > root 노드의 data
    }

    // 탐색 (반복)
    Node<T>* searchIter(Node<T>* node, T key){
        while(node != NULL){
            if(key == node->getData()) return node;     // key == root 노드의 data
            else if(key < node->getData()) node = node->getLeft();   // key < root 노드의 data
            else if(key > node->getData()) node = node->getRight();  // key > root 노드의 data
        }
        return NULL;    // 탐색이 실패한 경우 NULL 반환
    }

    // 삽입 (순환)
    void insertRecur(Node<T>* node, T key){
        Node<T>* newNode = new Node<T>(key, nullptr, nullptr);  // 새로운 key를 가지는 node 생성

        if(key == node->getData()){         // 트리에 이미 key값을 가지는 node가 있는 경우
            return;
        }else if(key < node->getData()){    // key < root 노드의 data
            if(node->getLeft() == NULL){
                node->setLeft(newNode);
            }else{
                insertRecur(node->getLeft(), key);
            }
        }else if(key > node->getData()){    // key > root 노드의 data
            if(node->getRight() == NULL){
                node->setRight(newNode);
            }else{
                insertRecur(node->getRight(), key);
            }
        }
    }

    // 삭제
    void remove(Node<T>* parentNode, Node<T>* deleteNode){
        // Case1. 삭제하려는 node가 leaf 노드인 경우
        if(deleteNode->isLeaf()){
            if(deleteNode == this->getRoot()){     // 삭제하려는 node가 root인 경우
                this->setRoot(nullptr);
            }else{
                if(parentNode->getLeft() == deleteNode){        // parent의 왼쪽 자식노드 삭제
                    parentNode->setLeft(nullptr);
                }else if(parentNode->getRight() == deleteNode){ // parent의 오른쪽 자식노드 삭제
                    parentNode->setRight(nullptr);
                }
            }
        }
        // Case2. 삭제하려는 node가 하나의 자식노드만 갖는 경우
        else if(deleteNode->getLeft() == NULL || deleteNode->getRight() == NULL){
            Node<T>* childNode = (deleteNode->getLeft() != NULL) ? deleteNode->getLeft() : deleteNode->getRight();  // 삭제할 node의 유일한 자식노드

            if(deleteNode == this->getRoot()){    // 삭제하려는 node가 root인 경우
                this->setRoot(childNode);
            }else{
                if(parentNode->getLeft() == deleteNode){        // parent의 왼쪽 자식노드에 childNode link
                    parentNode->setLeft(childNode);
                }else if(parentNode->getRight() == deleteNode){ // parent의 오른쪽 자식노드 childNode link
                    parentNode->setRight(childNode);
                }
            }
        }
        // Case3. 삭제하려는 node가 2개의 자식노드를 모두 갖는 경우
        else{
            // 삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색하는 과정
            Node<T>* succp = deleteNode;
            Node<T>* succ = deleteNode->getRight();
            while(succ->getLeft() != NULL){
                succp = succ;
                succ = succ->getLeft();
            }

            // 3-1. 후계자 노드의 부모와 후계자 노드의 자식 연결
            if(succp->getLeft() == succ){
                succp->setLeft(succ->getRight());
            }else{  // 후계자 노드가 삭제할 노드의 바로 오른쪽 자식인 경우
                succp->setRight(succ->getRight());
            }

            // 3-2. 삭제할 노드의 data를 후계자노드의 data로 대체
            deleteNode->setData(succ->getData());

            // 3-3. 삭제할 노드를 후계자노드로 변경 (후계자노드를 delete 하기 위해)
            deleteNode = succ;
        }

        delete deleteNode;  // memory 반납
    }

public:
    BinarySearchTree(){}
    ~BinarySearchTree(){}

    // 탐색
    Node<T>* search(T key){
        //return searchRecur(this->getRoot(), key);
        return searchIter(this->getRoot(), key);
    }

    // 삽입
    void insert(T key){
        if(this->isEmpty()){
            Node<T>* newNode = new Node<T>(key, nullptr, nullptr);  // 새로운 key를 가지는 node 생성
            this->setRoot(newNode);
        }else{
            insertRecur(this->getRoot(), key);
        }
    }

    // 삭제
    void remove(T key){
        if(this->isEmpty()){
            cout << "Tree is Empty" << endl;
            return;
        }

        // parentNode와 deleteNode를 찾는 과정
        Node<T>* parentNode = nullptr;          // 삭제하려는 node의 부모 node (최초 root의 부모노드는 없음)
        Node<T>* deleteNode = this->getRoot();    // 삭제하려는 node
        while(deleteNode != NULL && deleteNode->getData() != key){
            parentNode = deleteNode;
            deleteNode = (key < parentNode->getData()) ? parentNode->getLeft() : parentNode->getRight();
        }

        if(deleteNode == NULL){
            cout << "Key is not in Tree" << endl;
            return;
        }else{
            remove(parentNode, deleteNode);
        }

    }


};

int main(){
    BinarySearchTree<int> tree;

//    // 10개 node 삽입
//    tree.insert(35);
//    tree.insert(18);
//    tree.insert(7);
//    tree.insert(26);
//    tree.insert(12);
//    tree.insert(3);
//    tree.insert(68);
//    tree.insert(22);
//    tree.insert(30);
//    tree.insert(99);
//
//    // Calculate
//    cout << "전체 노드개수 : " << tree.getCount() << endl;
//    cout << "단말 노드개수 : " << tree.getLeafCount() << endl;
//    cout << "이진트리 높이 : " << tree.getHeight() << endl;
//
//    // Traversal
//    tree.preorder();
//    tree.inorder();
//    tree.postorder();
//    tree.levelorder();
//
//    // 삭제
//    cout << "==== 노드 3 삭제 ====" << endl;
//    tree.remove(3);
//    tree.levelorder();
//    cout << "==== 노드 68 삭제 ====" << endl;
//    tree.remove(68);
//    tree.levelorder();
//    cout << "==== 노드 18 삭제 ====" << endl;
//    tree.remove(18);
//    tree.levelorder();
//    cout << "==== 노드 35 삭제 ====" << endl;
//    tree.remove(35);
//    tree.levelorder();
//
//    // Last Calculate
//    cout << "전체 노드개수 : " << tree.getCount() << endl;
//    cout << "단말 노드개수 : " << tree.getLeafCount() << endl;
//    cout << "이진트리 높이 : " << tree.getHeight() << endl;

    // 10개 node 삽입
    tree.insert(5);
    tree.insert(3);
    tree.insert(9);
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(2);
    tree.insert(6);
    tree.insert(8);

    // 레벨 순회 결과
    tree.levelorder();

    cout << "==== 노드 9 삭제 ====" << endl;
    tree.remove(9);
    tree.levelorder();

    return 0;
}