/*
 * 2.4
 * 구조체 정의 및 사용
 */
#include <iostream>
#include <string>
using namespace std;

struct Person{
    string name;
    int age;
    char sex;
    double height;
};

void printer(Person p){
    cout << "이름 : " << p.name << endl;
    cout << "나이 : " << p.age << endl;
    cout << "성별 : " << (p.sex == 'M' ? "남자" : "여자") << endl;
}

int main() {

    // Person 구조체 선언 및 초기화
    Person p1;
    p1.name = "우수연";
    p1.age = 25;
    p1.sex = 'M';
    p1.height = 184.2;

    Person p2;
    p2.name = "아이유";
    p2.age = 28;
    p2.sex = 'F';
    p2.height = 161.7;

    // 키큰사람 출력
    if(p1.height > p2.height){
        printer(p1);
    }else{
        printer(p2);
    }

    return 0;
}