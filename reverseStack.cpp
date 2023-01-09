#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int> &St, int x){
        //base case
        if(St.empty()){
            St.push(x);
            return;
        }
        
        //save the top element
        int top = St.top();
        //pop out top element
        St.pop();
        //recursive call for remaining stack
        insertAtBottom(St, x);
        //push back the saved element
        St.push(top);
    }
    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        
        //save the top element
        int top = St.top();
        //pop the top element
        St.pop();
        //recursive call to delete remaining element
        Reverse(St);
        //insert at bottom the top element
        insertAtBottom(St, top);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}