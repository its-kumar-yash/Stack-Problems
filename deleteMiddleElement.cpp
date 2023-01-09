//Delete middle element from stack

#include<bits/stdc++.h>
using namespace std;

void solve(stack<int>&inputStack, int size, int count){
    // base case;
    if(count == size/2){
        inputStack.pop();
        return;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
    //recursive call
    solve(inputStack, size, count + 1);
    
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	int count = 0;
    solve(inputStack, N, count);
}


int main(){
    
    return 0;
}
