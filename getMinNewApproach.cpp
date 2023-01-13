//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           //check if stack empty or not
           if(s.empty()){
               return  -1;
           }
           // else return mini Element
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           //underflow condition
           if(s.empty()){
               return  -1;
           }
           // save stack top value
           int top = s.top();
           // save original value
           int original = minEle;
           
           //if top if greater or equal to mini
           // simply pop the top and return top's saved value
           if(top >= minEle){
               s.pop();
               return top;
               
           }
           //if top is smaller than mini
           // to retreive the original value from stack - use miniEle( original )
           // to change mini element to next minimum element - 2 * mini - top 
           else{
               minEle = 2 * minEle - top;
               s.pop();
               return original;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           //first element 
           if(s.empty()){
               s.push(x);
               minEle = x;
           }
           
           else{
               // if new element is greater than mini Element
               // simply push the element into stack 
               // No need to change mini element
               if(x >= minEle){
                   s.push(x);
               }
               //if new element is smaller than mini element
               // push fake value into stack - (val + val - mini)
               // store original value by updating mini Element - with new element
               else{
                   s.push(x + x - minEle);
                   minEle = x;
               }
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends