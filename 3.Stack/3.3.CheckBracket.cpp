/*
 * 3.3
 * Stack을 활용하여 괄호검사 알고리즘 구현
 */
#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool checkBracket(char* s){
    stack<char> stack;  // 괄호를 검사하기 위해 사용할 stack
    map<char, char> bracketMap = {{')', '('},
                                  {']', '['},
                                  {'}', '{'}};

    for(int i=0; s[i]!='\0'; i++){
        // 왼쪽 괄호를 만나는 경우 stack에 push
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stack.push(s[i]);
        }
        // 오른쪽 괄호를 만나는 경우 stack의 top과 비교
        if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(stack.empty()){
                return false;   // stack이 비어있는 경우 false
            }else{
                if(bracketMap.find(s[i])->second != stack.top()){
                    return false;   // stack의 top과 괄호의 짝이 맞지 않는 경우 false
                }else{
                    stack.pop();    // stack의 top과 괄호의 짝이 맞는 경우 pop
                }
            }
        }
    }

    // 최종적으로 stack이 empty된 경우 true, 아닌경우 flase
    if(stack.empty()){
        return true;
    }else{
        return false;
    }
}

int main() {
    char* c1 = "1. {A[(i+1)]=0;}";
    char* c2 = "2. if((i==0)&&(j==0)";
    char* c3 = "3. A[(i+1])=0;";

    cout << c1 << " : " << (checkBracket(c1) ? "True" : "False") << endl;
    cout << c2 << " : " << (checkBracket(c2) ? "True" : "False") << endl;
    cout << c3 << " : " << (checkBracket(c3) ? "True" : "False") << endl;
    return 0;
}