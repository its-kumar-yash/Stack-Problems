// You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

// A 0-indexed string num of length n + 1 is created using the following conditions:

// num consists of the digits '1' to '9', where each digit is used at most once.
// If pattern[i] == 'I', then num[i] < num[i + 1].
// If pattern[i] == 'D', then num[i] > num[i + 1].
// Return the lexicographically smallest possible string num that meets the conditions.

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        //answer string
        string ans = "";
        
        stack<int> st;
        
        //number count from 1 - 9 
        int num = 1;
        
        for(int i = 0; i < S.length(); i++){
            //if "D"
            // - push num into stack
            // - increase num
            if(S[i] == 'D'){
                st.push(num);
                num++;
            }
            //if 'I'
            // - push num into stack
            // - increase num
            // - empty the stack and store into ans
            else if(S[i] == 'I'){
                st.push(num);
                num++;
                
                while(!st.empty()){
                    int top = st.top();
                    ans += to_string(top);
                    st.pop();
                }
            }
        }
        
        st.push(num);
        while(!st.empty()){
            int top = st.top();
            ans += to_string(top);
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends