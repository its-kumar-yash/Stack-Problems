// You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution
{
    int mini;
    stack<int> st;

public:
    /*returns min element from stack*/
    int getMin()
    {

        if (st.empty())
        {
            return -1;
        }
        return mini;
    }

    /*returns poped element from stack*/
    int pop()
    {

        if (st.empty())
        {
            return -1;
        }
        int curr = st.top();
        st.pop();
        if (curr > mini)
        {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMin;
        }
    }

    /*push element x into the stack*/
    void push(int x)
    {

        if (st.empty())
        {
            st.push(x);
            mini = x;
        }
        else
        {
            if (x < mini)
            {
                int val = 2 * x - mini;
                st.push(val);
                mini = x;
            }
            else
            {
                st.push(x);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        Solution ob;
        while (q--)
        {
            int qt;
            cin >> qt;
            if (qt == 1)
            {
                // push
                int att;
                cin >> att;
                ob.push(att);
            }
            else if (qt == 2)
            {
                // pop
                cout << ob.pop() << " ";
            }
            else if (qt == 3)
            {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends