#include<bits/stdc++.h>
using namespace std;


string reverseString(string s){

    //creating a stack of char type
    stack<char> st;
    
    //push string characters to stack
    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }

    string ans = "";

    while(st.size() != 0){

        char ch = st.top();
        ans = ans + ch;
        st.pop();

    }

    return ans;
}

int main(){
    
    string str;
    cin>>str;

    cout<<reverseString(str)<<endl;

    return 0;
}
