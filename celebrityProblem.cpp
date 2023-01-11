//A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
//A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.


// Microsoft, Google, and other

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {   
        stack<int> st;
        //step 1 - put all element into stack
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        //step 2 - Check till stack size is 1
        while(st.size() > 1){
            //pop two element from stack
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            //check
            //if a knows b, push b into stack again
            if(M[a][b] == 1){
                st.push(b);
            }
            //if b knows a, push a into stack again
            if(M[b][a] == 1){
                st.push(a);
            }
        }
        
        //remainaing element is a potential answer
        int ans = st.top();
        
        bool rowCheck = false;
        int zeroCount = 0;
        
        //check 1 - check all 0's in row
        for(int i = 0; i < n; i++){
            if(M[ans][i] == 0){
                zeroCount++;
            }
        }
        
        
        if(zeroCount == n){
            rowCheck = true;
        }
        
        
        bool colCheck = false;
        int oneCount = 0;
        
        //check 2 - check all 1's in col except diagonal
        for(int i = 0; i < M.size(); i++){
            if(ans == i){
                continue;
            }
            else if(M[i][ans] == 1){
                oneCount++;
            }
        }
        
        if(oneCount == n - 1){
            colCheck = true;
        }
        
        if(colCheck && rowCheck){
            return ans;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}