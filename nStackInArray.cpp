//implement n stacks using a single array of size s

//operations
// - Push( X, M);
// - pop(M)

#include <bits/stdc++.h> 
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;
    
    int s;
    int n;
    
    int freeSpot;
    
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {    
        n = N;
        s = S;
        
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        //top initialize
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }
        
        //next initialize
        for(int i = 0; i < s; i++){
            next[i] = i + 1;
        }
        
        next[s - 1] = -1;
        
        freeSpot = 0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check overflow
        if(freeSpot == -1){
            return false;
        }
        
        // find index
        int index = freeSpot;
        
        //freespot update
        freeSpot = next[index];
        
        //insert element into array
        arr[index] = x;
        
        //update next
        next[index] = top[m - 1];
        
        //update top
        top[m - 1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow
        if(top[m - 1] == -1){
            return -1;
        }
        
        int index = top[m - 1];
        
        top[m - 1] = next[index];
        
        next[index] = freeSpot;
        
        freeSpot = index;
        
        return arr[index];
    }
};