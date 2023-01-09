
//Design two stacks using one array

#include <bits/stdc++.h> 
using namespace std;


class TwoStack {
    //variables required
    int top1;
    int top2;
    int *arr;
    int size;
    
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        //atleast one empty is present
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1 >= 0){
            int temp = arr[top1];
            top1--;
            return temp;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2 < size){
            int temp = arr[top2];
            top2++;
            return temp;
        }
        else{
            return -1;
        }
    }
};
