//Maximum Rectangular Area in a Histogram

// Google MicroSoft



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> rightBoundary(n); // next smaller element index to the right
        
        stack<long long> st1;
        st1.push(n - 1);
        rightBoundary[n - 1] = n;
        
        for(int i = n - 2; i >= 0; i--){
            
            while( !st1.empty() && arr[i] <= arr[st1.top()]){
                st1.pop();
            }
            
            if(st1.empty()){
                rightBoundary[i] = n;
            }
            else{
                rightBoundary[i] = st1.top();
            }
            
            st1.push(i);
        }
        
        
        vector<long long> leftBoundary(n); // next smaller element index to the left
        
        stack<long long> st2;
        st2.push(0);
        leftBoundary[0] = -1;
        
        for(int i = 1; i < n; i++){
            
            while( !st2.empty() && arr[i] <= arr[st2.top()]){
                st2.pop();
            }
            
            if(st2.empty()){
                leftBoundary[i] =  -1;
            }
            else{
                leftBoundary[i] = st2.top();
            }
            
            st2.push(i);
        }
        
        
        
        long long maxArea = INT_MIN; // to store maximum area
        
        for(int i = 0; i < n; i++){
            
            long long width = rightBoundary[i] - leftBoundary[i] - 1; //expression to calculate width            
            long long area = width * arr[i]; // area = length * width
            
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}