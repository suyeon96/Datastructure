/*
 * 3.4
 * Stack을 활용하여 중위표기식 -> 후위표기식 -> 계산 알고리즘 구현
 */
#include <iostream>
#include <stack>
using namespace std;

// 연산자 우선순위 계산
int getOpPriority(char op){
    switch(op){
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

// 중위연산식 -> 후위연산식
string infixToPostfix(string s){
    stack<char> stack;              // 연산자 stack
    string postfixExpression = "";  // 후위연산식

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {  // 연산자
            if (stack.empty()) {
                stack.push(s[i]);
            } else {
                // 현재 연산자 우선순위보다 stack의 top 연산자 우선순위가 높을때 까지 pop 후 현재 연산자 push
                while (!stack.empty() && getOpPriority(s[i]) <= getOpPriority(stack.top())) {
                    postfixExpression.push_back(stack.top());
                    stack.pop();
                }
                stack.push(s[i]);
            }
        }else if(s[i]=='('){    // 왼쪽괄호
            stack.push(s[i]);
        }else if(s[i]==')'){    // 오른쪽괄호
            // 왼쪽괄호 위에 쌓여있는 모든 연산자 pop 후 왼쪽괄호 삭제
            while(!stack.empty() && stack.top()!='('){
                postfixExpression.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }else{  // 피연산자
            if(s[i]==' '){
                continue;
            }else{
                postfixExpression.push_back(s[i]);
            }
        }
    }

    // 스택의 남은 연산자를 모두 pop
    while(!stack.empty()){
        postfixExpression.push_back(stack.top());
        stack.pop();
    }

    return postfixExpression;
}

// 후위연산식 계산
double calculatePostfix(string s){
    stack<int> stack;               // 피연산자 stack
    int step = 1;                   // 연산 순서

    for(int i=0; s[i]!='\0'; i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {  // 연산자
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();
            cout << "   " << step++ << ". " << num2 << s[i] << num1 << endl;

            switch(s[i]){
                case '+' : stack.push(num1 + num2); break;
                case '-' : stack.push(num1 - num2); break;
                case '*' : stack.push(num1 * num2); break;
                case '/' : stack.push(num1 / num2); break;
            }
        }else{
            stack.push(s[i] - '0');
        }
    }

    return stack.top();
}

int main() {
    cout << "==== infix -> postfix ====" << endl;
    string infixExpression = "6+8/(2*3)+1";
    cout << "- 중위연산식 : " << infixExpression << endl;
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "- 후위연산식 : " << postfixExpression << '\n' << endl;

    cout << "==== calculate posfix ====" << endl;
    cout << "- 연산순서" << endl;
    double result = calculatePostfix(postfixExpression);
    cout << "- 답 : " << result << endl;

    return 0;
}