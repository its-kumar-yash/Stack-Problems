#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    // edge case - if length of string is odd
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    // remove valid part from string and generate invalid string
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];
        // if ch is opening bracket, push it into stack
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            // if ch is closing bracket
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    // Now, stack contains the invalid expression
    int a = 0; // a - count of opening brackets
    int b = 0; // b - count of closing brackets

    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }

    // expression for answer
    int ans = (a + 1) / 2 + (b + 1) / 2;

    return ans;
}