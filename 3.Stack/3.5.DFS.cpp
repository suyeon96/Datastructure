/*
 * 3.5
 * Stack을 활용하여 미로탐색(DFS) 알고리즘 구현
 */
#include <iostream>
#include <stack>
using namespace std;

struct Location2D{
    int row;    // 현재 위치의 행
    int col;    // 현재 위치의 열

    Location2D(int r, int c){
        row = r;
        col = c;
    }
};

const int MAX_SIZE = 6;
char map[MAX_SIZE][MAX_SIZE] ={
        {'1','1','1','1','1','1'},
        {'e','0','1','0','0','1'},
        {'1','0','0','0','1','1'},
        {'1','0','1','0','1','1'},
        {'1','0','1','0','0','x'},
        {'1','1','1','1','1','1'}
};

// (row, col) 위치에 갈 수 있는지 검사
bool isValidLoc(int row, int col){
    if(row<0 || col<0 || row>MAX_SIZE || col>MAX_SIZE){
        return false;
    }else{
        return map[row][col] == '0' || map[row][col] == 'x' ? true : false;
    }
}

// 시각적으로 Map 보여주기
void printMap(int row, int col){
    cout << '\n' << "======= [" << row << ", " << col << "] =======" << endl;
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            if(i==row && j==col){   // 현재 위치
                cout << " ❌️ ";
            }else{
                if(map[i][j] == '1') cout << " ⬛️ ";
                if(map[i][j] == 'x') cout << " 🚩️ ";
                if(map[i][j] == '0') cout << " ◻️ ";
                if(map[i][j] == '.') cout << " 👣️ ";
            }
        }
        cout << endl;
    }
}

int main() {
    stack<Location2D> locStack;
    locStack.push(Location2D(1,0));    // start 좌표

    while(!locStack.empty()){
        // 현재 위치를 구하고 stack에서 삭제
        Location2D here = locStack.top();
        locStack.pop();
        int row = here.row;
        int col = here.col;

        printMap(row, col);

        if(map[row][col] == 'x'){
            cout << "SUCCESS!!" << endl;
            return 0;
        }else{
            map[row][col] = '.';
            if(isValidLoc(row, col-1))  // 좌
                locStack.push(Location2D(row, col-1));
            if(isValidLoc(row, col+1))  // 우
                locStack.push(Location2D(row, col+1));
            if(isValidLoc(row-1, col))  // 상
                locStack.push(Location2D(row-1, col));
            if(isValidLoc(row+1, col))  // 하
                locStack.push(Location2D(row+1, col));
        }
    }

    cout << "FAILED!!" << endl;
    return 0;
}