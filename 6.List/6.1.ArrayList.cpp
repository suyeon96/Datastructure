/*
 * 6.1
 * ArrayList 구현
 */
#include <iostream>
using namespace std;

#define MAX_LIST_SIZE 100

template <typename T>
class ArrayList {
private:
    T data[MAX_LIST_SIZE];
    int length;

public:
    ArrayList(){
        length = 0;
    }
    ~ArrayList(){}

    // [삽입] list의 idx번째에 요소 x 추가
    void insert(int idx, T x){
        if(isFull()){
            cout << "List full error" << endl;
            return;
        }
        if(idx<0 || idx>length){
            cout << "insert index error" << endl;
            return;
        }

        for(int i=length; i>idx; i--){  // idx 뒤의 요소들을 한칸씩 뒤로 이동
            data[i] = data[i-1];
        }
        data[idx] = x;  // idx번째에 x 대입

        length++;
    }

    // [삭제] idx번째 요소를 리스트에서 제거 후 반환
    T remove(int idx){
        if(isEmpty()){
            cout << "List empty error" << endl;
            exit(EXIT_FAILURE);
        }
        if(idx<0 || idx>length){
            cout << "remove index error" << endl;
            exit(EXIT_FAILURE);
        }

        T x = data[idx];                    // 삭제될 요소
        for(int i=idx+1; i<length; i++){    // idx 뒤의 요소들을 한칸씩 앞으로 이동
            data[i-1] = data[i];
        }

        length--;
        return x;
    }

    // idx번째 항목 반환
    T getEntry(int idx){
        return data[idx];
    }

    // 요소 x가 리스트에 있는지 확인
    bool find(T x){
        for(int i=0; i<length; i++){
            if(data[i] == x){
                return true;
            }
        }
        return false;
    }

    // idx번째 요소를 x로 변경
    void replace(int idx, T x){
        data[idx] = x;
    }

    // List size 반환
    int size(){
        return length;
    }

    // List 출력
    void display() {
        cout << "List : ";
        for(int i=0; i<size(); i++){
            cout << "[" << data[i] << "]";
        }
        cout << endl;
    }

    bool isEmpty(){
        return length == 0;
    }
    bool isFull(){
        return length == MAX_LIST_SIZE;
    }
};

int main(){
    ArrayList<char> list;

    cout << "===== insert list x5 =====" << endl;
    list.insert(0, 'a');
    list.insert(1, 'b');
    list.insert(2, 'c');
    list.insert(list.size(), 'd');  // list 마지막에 'd' 삽입
    list.insert(4, 'e');
    cout << "size : " << list.size() << endl;
    list.display();

    cout << "===== remove index3 =====" << endl;
    list.remove(3); // 3번째 요소 삭제
    cout << "size : " << list.size() << endl;
    list.display();

    cout << "===== insert 'f' at index1 =====" << endl;
    list.insert(1, 'f');
    cout << "size : " << list.size() << endl;
    list.display();

    cout << "===== replace 'g' at index0 =====" << endl;
    list.replace(0, 'g');
    list.display();

    return 0;
}