// Given a string of balanced expression, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Print Yes if redundant, else No.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            //case 1 - if ch is opening bracket or operator
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            
            //case 2 - if ch is closing bracket or lowercase 
            else{
                if(ch == ')'){
                    int isRedundant = 1;
                    
                    while(st.top() != '('){
                        //check top element
                        int top = st.top();
                        //if it is operator, make isRedundant = 0
                        if(top == '+' || top == '-' || top == '*' || top == '/'){
                            isRedundant = 0;
                        }
                        
                        st.pop();
                    }
                    
                    if(isRedundant == 1){
                        return 1;
                    }
                    //remove the opening bracket
                    st.pop();
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}
