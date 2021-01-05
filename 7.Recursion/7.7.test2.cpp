/*
 * 7.6
 * 문자열의 내용을 반대로 바꾸는 순환적인 함수 reverse()를 구현하라.
 * 예를 들어 reverse("ABCDE")는 "EDCBA"를 반환해야 한다.
 */
#include <iostream>
using namespace std;

string reverse(string text){
    if(text.length() == 0) return "";
    else return string(1, text.back()).append(reverse(text.substr(0, text.length()-1)));
}

int main(){
    string text = "ABCDE";
    cout << reverse(text) << endl;

    return 0;
}