/*
 * 8.1
 * 이진트리
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

int main(){
    BinaryTree<char> tree;

    // Create Node
    Node<char> *d = new Node<char>('D', nullptr, nullptr );
    Node<char> *b = new Node<char>('B', d, nullptr );
    Node<char> *g = new Node<char>('G', nullptr, nullptr );
    Node<char> *h = new Node<char>('H', nullptr, nullptr );
    Node<char> *e = new Node<char>('E', g, h );
    Node<char> *f = new Node<char>('F', nullptr, nullptr );
    Node<char> *c = new Node<char>('C', e, f );
    Node<char> *a = new Node<char>('A', b, c );

    // Create Tree
    tree.setRoot(a);

    // Traversal
    tree.preorder();
    tree.inorder();
    tree.postorder();
    tree.levelorder();

    // Calculate
    cout << "전체 노드개수 : " << tree.getCount() << endl;
    cout << "단말 노드개수 : " << tree.getLeafCount() << endl;
    cout << "이진트리 높이 : " << tree.getHeight() << endl;

    return 0;
}