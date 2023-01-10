#include<bits/stdc++.h>
using namespace std;

int precedence(char optor){
    if(optor == '+' || optor == '-' ){
        return 1;
    }
    if( optor == '*' || optor == '/'){
        return 2;
    }
}

int operations(int val1, int val2, char optor){
    if(optor == '+'){
        return val1 + val2;
    }
    if(optor == '-'){
        return val1 - val2;
    }
    if(optor == '*'){
        return val1 * val2;
    }
    if(optor == '/'){
        return val1 / val2;
    }
}

int infixEvaluation(string str){
    
    //operator and operands stack
    stack<int> opnds;
    stack<char> optors;

    for(int i = 0; i < str.length(); i++){

        char ch = str[i];

        //if operand, push into operand stack
        if(ch >= '0' && ch <= '9'){
            opnds.push(ch - '0');
        }
        //if open bracket, push into operator stack
        else if(ch == '('){
            optors.push(ch);
        }
        //if close bracket, pop till you get open bracket
        else if(ch == ')'){
            while(!optors.empty() && optors.top() != '('){
                char optor = optors.top();
                optors.pop();
                int val2 = opnds.top();
                opnds.pop();
                int val1 = opnds.top();
                opnds.pop();

                int opv = operations(val1, val2, optor);
                opnds.push(opv);
            }
            if(!optors.empty()){
                optors.pop();
            }
        }
        //if operators, pop all greater or equal priority operators
        else{
            while(!optors.empty() && optors.top() != '(' && precedence(ch) <= precedence(optors.top())){
                int v2 = opnds.top();
                opnds.pop();
                int v1 = opnds.top();
                opnds.pop();
                char optor = optors.top();
                optors.pop();

                int opv = operations(v1, v2, optor);
                opnds.push(opv);
            }
            optors.push(ch);
        }
    }

    while(!optors.empty()){
        int v2 = opnds.top();
        opnds.pop();
        int v1 = opnds.top();
        opnds.pop();
        char optor = optors.top();
        optors.pop();

        int opv = operations(v1, v2, optor);
        opnds.push(opv);
    }

    int answer = opnds.top();

    return answer; 
}

//expression - 2 + ( 5 - 3 * 6 / 2)

int main(){
    string str = "2+(5-3*6/2)";
    cout<<infixEvaluation(str)<<endl;
    return 0;
}