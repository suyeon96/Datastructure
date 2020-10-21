/*
 * 2.5
 * 클래스 정의 및 사용
 */
#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(){}
    ~Point(){}
    Point(int a, int b){
        x = a;
        y = b;
    }

    void addPoint(int a, int b);
    void showPoint();
};

void Point::addPoint(int a, int b){
    x += a;
    y += b;
}
void Point::showPoint(){
    cout << "x : " << x << ", y : " << y << endl;
}

int main(){
    Point p1(2, 4);
    Point p2;

    p1.addPoint(10, 10);
    p2.addPoint(10, 10);

    p1.showPoint();
    p2.showPoint();

    return 0;
}