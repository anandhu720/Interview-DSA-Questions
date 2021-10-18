// Given an array of distinct elements. Find the third largest element in it.

// Your Task
// Complete the function thirdLargest() which takes the array a[] and the size of the array, n, as input parameters and returns the third largest element in the array.
// It return -1 if there are less than 3 elements in the given array.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int thirdLargest(int a[], int n)
    {
        //Your code here
        sort(a, a + n);
        if (n >= 3)
        {
            int x = a[n - 3];
            return x;
        }
        else
            return -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.thirdLargest(a, n) << endl;
    }
} // } Driver Code Ends