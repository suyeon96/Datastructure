/*
 * 2.7
 * 희소 다항식
 */
#include <iostream>
using namespace std;

#define MAX_TERMS 80

struct Term{        // 하나의 항을 표현하는 구조체
    int expo;       // 항의 지수
    float coef;     // 항의 계수
};

class SparsePoly{           // 희소 다항식 클래스
    int nTerms;             // 항의 개수
    Term term[MAX_TERMS];   // 항의 배열

public:
    SparsePoly(){
        nTerms = 0;
    }

    void read(){
        cout << "항의 개수 입력 : ";
        cin >> nTerms;
        for(int i=0; i<nTerms; i++){
            Term tmp;
            cout << "- 최고차항부터 순차적으로 계수와 지수 입력 (" << i+1 << "/" << nTerms << ") : ";
            cin >> tmp.coef >> tmp.expo;
            term[i] = tmp;
        }
    }

    // 다항식 내용 출력
    void display(char *str = (char*)"SPoly = "){
        cout << "- " << str;
        for(int i=0; i<nTerms; i++){
            if(i+1==nTerms){
                if(term[i].expo == 0){  // 0승
                    cout << term[i].coef << endl;
                }else{
                    cout << term[i].coef << "x^" << term[i].expo << endl;;
                }
            }else{
                cout << term[i].coef << "x^" << term[i].expo << " + ";
            }
        }
    }

    // 두 다항식 덧셈
    void add(SparsePoly a, SparsePoly b){
        int i=0, j=0, k=0;
        while(i<a.nTerms || j<b.nTerms){
            if(a.term[i].expo > b.term[j].expo){    // 두 다항식의 최고차항 지수 비교
                term[k++] = a.term[i++];
            }else if(a.term[i].expo < b.term[j].expo){
                term[k++] = b.term[j++];
            }else{  // 두 다항식에서 겹치는 지수가 있는 경우
                Term tmp;
                tmp.expo = a.term[i].expo;
                tmp.coef = a.term[i++].coef + b.term[j++].coef;
                term[k++] = tmp;
            }
        }
        nTerms = k;
    }
};

int main(void){
    SparsePoly a, b, c;

    a.read();
    b.read();
    c.add(a, b);

    cout << "================= Display =================" << endl;
    a.display((char*)"A = ");
    b.display((char*)"B = ");
    c.display((char*)"A+B = ");
    return 0;
}