

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> arr){
    int n = arr.size();
    vector<int> nge(n);

    stack<int> st;
    //push last element of array into array
    // and update the last element of result array to -1
    st.push(arr[n - 1]);
    nge[n - 1] = - 1;

    for(int i = n - 2; i >= 0; i--){

        int curr = arr[i];
        //step 1 - pop element from stack till you get stack top greater than current element
        while(!st.empty() && st.top() <= curr){
            st.pop();
        }

        //step 2 - in result array, update the current index to stack top element
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }

        //step 3 - push the curr element to the stack
        st.push(curr);
    }

    return nge;
}

int main(){
    
    vector<int> arr = {2,5,9,3,1,12,6,8,7};

    vector<int> nge = nextGreaterElement(arr);

    for(int i : nge){
        cout<<i<<" ";
    }

    return 0;
}