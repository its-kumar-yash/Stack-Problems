
// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
// The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.


//Variation of Next Greater Element to the left( using index approach)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n){
        
        //result vector
        vector<int> result(n);
        
        stack<int> st;
        //push the index of first element of array
        st.push(0);
        result[0] = 1;
        
        for(int i = 1; i < n; i++){
            int curr = price[i];
            //step 1 - pop element from stack till you find element greater than current element
            while(!st.empty() && curr >= price[st.top()]){
                st.pop();
            }
            
            //step 2 - if the stack is empty, span will be (i + 1)
            // if not empty, span will be (i - st.top())
            if(st.empty()){
                result[i] = i + 1;
            }
            else{
                result[i] = i - st.top();
            }
            
            //step 3 - push current element's index into stack
            st.push(i);
        }
        
        return result;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}