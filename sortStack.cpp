#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int x){
    //base case
    if(stack.empty()){
        stack.push(x);
        return;
    }
    //insert element whenever you get a smaller element
    if(!stack.empty()){
        if(x > stack.top()){
            stack.push(x);
            return;
        }
    }
    
    int top = stack.top();
    
    stack.pop();
    
    sortedInsert(stack, x);
    
    stack.push(top);
}

void sortStack(stack<int> &stack)
{    
    //base case
	if(stack.empty()){
        return;
    }
    
    //save the top element
    int top = stack.top();
    
    //pop the top element
    stack.pop();
    
    //recursive call to sort remaining stack
    sortStack(stack);
    
    //insert element in sorted order
    sortedInsert(stack, top);
}