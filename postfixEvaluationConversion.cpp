#include<bits/stdc++.h>
using namespace std;

int operations(int v1, int v2, char op){
    if(op == '+'){
        return v1 + v2;
    }
    if(op == '-'){
        return v1 - v2;
    }
    if(op == '*'){
        return v1 * v2;
    }
    if(op == '/'){
        return v1 / v2;
    }
}

int evaluatePostfix(string str){
    stack<int> valueStack;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch >= '0' && ch <= '9'){
            valueStack.push(ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(!valueStack.empty()){
                int v2 = valueStack.top();
                valueStack.pop();
                int v1 = valueStack.top();
                valueStack.pop();

                int res = operations(v1, v2, ch);
                valueStack.push(res);
            }
        }
    }

    return valueStack.top();
}

string postfixToInfix(string str){
    stack<string> infixStack;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch >= '0' && ch <= '9'){
            string s = string(1, ch);

            infixStack.push(s);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(!infixStack.empty()){
                string v2 = infixStack.top();
                infixStack.pop();
                string v1 = infixStack.top();
                infixStack.pop();

                string res = "(" + v1 + ch + v2 + ")"; 
                infixStack.push(res);
            }
        }
    }

    return infixStack.top();
}

string postfixToPrefix(string str){
    stack<string> prefixStack;

    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch >= '0' && ch <= '9'){
            string s = string(1, ch);

            prefixStack.push(s);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            if(!prefixStack.empty()){
                string v2 = prefixStack.top();
                prefixStack.pop();
                string v1 = prefixStack.top();
                prefixStack.pop();

                string res = ch + v1 + v2; 
                prefixStack.push(res);
            }
        }
    }

    return prefixStack.top(); 
}


int main(){
    
    string str = "264*8/+3-";

    cout<<evaluatePostfix(str)<<endl;

    cout<<postfixToInfix(str)<<endl;

    cout<<postfixToPrefix(str)<<endl;

    return 0;
}