/*
Given a street of N houses (a row of houses), each house having K amount of money kept inside; now there is a thief 
who is going to steal this money but he has a constraint/rule that he cannot steal/rob two adjacent houses. 
Find the maximum money he can rob.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maximizeMoney(int N, int K)
    {
        // code here
        if (N % 2 == 0)
        {
            N /= 2;
            return (N * K);
        }
        else if (N % 2 != 0)
        {
            N = N / 2;
            N += 1;
            return (N * K);
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;

        cin >> N >> K;

        Solution ob;
        cout << ob.maximizeMoney(N, K) << endl;
    }
    return 0;
} // } Driver Code Ends