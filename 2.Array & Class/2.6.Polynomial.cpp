/*
 * 2.6
 * 다항식
 */
#include <iostream>
using namespace std;

#define MAX_DEGREE 80

class Polynomial{
    int degree;    // 최고차항
    float coef[MAX_DEGREE];    // 계수 배열
public:
    Polynomial(){
        degree = 0;
    }

    // 다항식 내용 입력
    void read(){
        cout << "다항식 최고 차수를 입력하시오 : ";
        cin >> degree;
        cout << "각 항의 계수를 입력하시오 (" << degree+1 << "개) : ";
        for(int i=0; i<=degree; i++){
            cin >> coef[i];
        }
    }

    // 다항식 내용 출력
    void display(char *str = (char*)"Poly = "){
        cout << "- " << str;
        for(int i=0; i<=degree; i++){
            if(i==degree){  // 0승
                cout << coef[i] << endl;
            }else{
                cout << coef[i] << "x^" << degree-i << " + ";
            }
        }
    }

    // 두 다항식 덧셈
    void add(Polynomial a, Polynomial b){
        if(a.degree > b.degree){
            *this = a;
            for(int i=0; i<=b.degree; i++){
                coef[i+(degree-b.degree)] += b.coef[i];
            }
        }else{
            *this = b;
            for(int i=0; i<=a.degree; i++){
                coef[i+(degree-a.degree)] += a.coef[i];
            }
        }
    }
};

int main(void){
    Polynomial a, b, c;

    a.read();
    b.read();
    c.add(a,b);

    a.display((char*)"A = ");
    b.display((char*)"B = ");
    c.display((char*)"A+B = ");
    return 0;
}