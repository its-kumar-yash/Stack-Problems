//Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

// google, microsoft, amazon

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {   
        vector<int> result;
        
        //step 1 - create next greater element index array
        vector<int> nge(n);
       
        stack<int> st;
       
        st.push(n - 1);
        nge[n - 1] = n; // n - denotes the infinity
        
        for(int i = n - 2; i >= 0; i--){
            
            while( !st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                nge[i] = n;
            }
            else{
                nge[i] = st.top();
            }
            
            st.push(i);
        }
        
        //step 2 - move two pointer
        int j = 0;
        for(int i = 0; i <= n - k; i++){
            if(j < i){
                j = i;
            }
            
            while(nge[j] < i + k){
                j = nge[j];
            }
            
            result.push_back(arr[j]);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}