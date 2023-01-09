#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr){
    int n = arr.size();
    vector<int> nse(n);

    stack<int> st;
    //push last element of array into stack
    //and update result array last element with -1
    st.push(arr[n - 1]);
    nse[n - 1] = -1;

    for(int i = n - 2; i >= 0; i--){

        int curr = arr[i];

        // step 1 - pop element from stack till you find the element smaller than curr element
        while( !st.empty() && st.top() >= curr){
            st.pop();
        }

        //step 2 - update the result with top element of stack
        if(st.empty()){
            nse[i] = -1;
        }
        else{
            nse[i] = st.top();
        }

        //step3 - push the current element into stack
        st.push(curr);
    }

    return nse;
}

int main(){
    
    vector<int> arr = {2,5,9,3,1,12,6,8,7};

    vector<int> nge = nextSmallerElement(arr);

    for(int i : nge){
        cout<<i<<" ";
    }

    return 0;
}