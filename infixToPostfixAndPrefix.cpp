#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;

int precedence(char opt){
    if(opt == '+' || opt == '-' ){
        return 1;
    }
    if(opt == '*' || opt == '/' ){
        return 2;
    }
}

string infixToPrefix(string str){
    // create stack
    stack<string> pre; // prefix stack
    stack<char> optor; //operator stack

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];

        //if operand - a to z, A to Z, 0 to 9
        if( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ){
            string s = string(1, ch);
            pre.push(s);
        }
        //if open bracket, push into operator stack
        else if( ch == '('){
            optor.push(ch);
        }
        //if closing bracket, pop till open bracket
        else if( ch == ')'){

            while( !optor.empty() && optor.top() != '('){
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                char opv = optor.top();
                optor.pop();

                string res = opv + v1 + v2;
                pre.push(res);
            }

            if( !optor.empty()){
                optor.pop();
            }
        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            
            while( !optor.empty() && optor.top() != '(' && precedence(ch) <= precedence(optor.top())){
                string v2 = pre.top();
                pre.pop();
                string v1 = pre.top();
                pre.pop();
                char opv = optor.top();
                optor.pop();

                string res = opv + v1 + v2;
                pre.push(res);
            }

            optor.push(ch);
        }
    }

    //at end if stack is not empty

    while(!optor.empty()){
        string v2 = pre.top();
        pre.pop();
        string v1 = pre.top();
        pre.pop();
        char opv = optor.top();
        optor.pop();

        string res = opv + v1 + v2;
        pre.push(res);
    }


    return pre.top();
}

string infixToPostfix(string str){
    // create stack
    stack<string> post; // prefix stack
    stack<char> optor; //operator stack

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];

        //if operand - a to z, A to Z, 0 to 9
        if( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ){
            string s = string(1, ch);
            post.push(s);
        }
        //if open bracket, push into operator stack
        else if( ch == '('){
            optor.push(ch);
        }
        //if closing bracket, pop till open bracket
        else if( ch == ')'){

            while( !optor.empty() && optor.top() != '('){
                string v2 = post.top();
                post.pop();
                string v1 = post.top();
                post.pop();
                char opv = optor.top();
                optor.pop();

                string res = v1 + v2 + opv;
                post.push(res);
            }

            if( !optor.empty()){
                optor.pop();
            }
        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            
            while( !optor.empty() && optor.top() != '(' && precedence(ch) <= precedence(optor.top())){
                string v2 = post.top();
                post.pop();
                string v1 = post.top();
                post.pop();
                char opv = optor.top();
                optor.pop();

                string res = v1 + v2 + opv;
                post.push(res);
            }

            optor.push(ch);
        }
    }

    //at end if stack is not empty

    while(!optor.empty()){
        string v2 = post.top();
        post.pop();
        string v1 = post.top();
        post.pop();
        char opv = optor.top();
        optor.pop();

        string res = v1 + v2 + opv;
        post.push(res);
    }


    return post.top();
}


int main(){
    string str = "a*(b-c)/d+e";
    cout<<infixToPrefix(str)<<endl;
    cout<<infixToPostfix(str)<<endl;
    return 0;
}