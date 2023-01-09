#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& myStack, int x){
    //base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    
    //save the top element
    int num = myStack.top();
    
    //pop out the top element
    myStack.pop();
    
    //recursive call
    solve(myStack, x);
    
    //pushing element again
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    
    return myStack;
}
