/*
 * 7.4
 * BW 이미지 영역채색
 */
#include <iostream>
#include <vector>
using namespace std;

#define WIDTH 20
#define HEIGHT 9

// 근접 4방향 화소가 이어져있는지 판단하여 labeling
void labelComponent(unsigned int img[HEIGHT][WIDTH], int x, int y, int label){
    if(x<0 || y<0 || x>=WIDTH || y>=HEIGHT){    // 이미지 영역 밖인 경우 return
        return;
    }

    if (img[y][x] == 9){    // labeling 처리가 안된 black 픽셀인 경우
        img[y][x] = label;  // 해당 픽셀에 label값 부여

        // (4방향 연결) 좌,상,우,하 방향으로 순환호출
        labelComponent(img, x-1, y, label);
        labelComponent(img, x, y-1, label);
        labelComponent(img, x+1, y, label);
        labelComponent(img, x, y+1, label);
    }
}

// BW 이미지 영역채색
void blobColoring(unsigned int img[HEIGHT][WIDTH]){
    int label = 1;  // label 초기화

    // [0,0] 화소부터 모든 화소에 대해 차례대로 loop 돌면서 labeling 처리가 안된 화소인 경우 labelComponent() 호출
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            if(img[y][x] == 9){
                labelComponent(img, x, y, label++);
            }
        }
    }
}

// 이미지 출력
void printImage(unsigned int img[HEIGHT][WIDTH]){
    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            if(img[y][x] == 0){
                cout << ".";
            }else{
                cout << img[y][x];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    unsigned int image[HEIGHT][WIDTH] = {0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
                                          9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
                                          0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
                                          0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
                                          0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
                                          9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
                                          9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
                                          9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
                                          0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9};

    cout << "<Original Image>" << endl;
    printImage(image);
    cout << "<Labelled Image>" << endl;
    blobColoring(image);
    printImage(image);

    return 0;
}