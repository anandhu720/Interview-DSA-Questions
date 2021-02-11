/*
Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. 
Find the missing element.
*/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int> &array, int n);

// Position this line where user code will be pasted.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

int MissingNumber(vector<int> &array, int n)
{
    // Your code goes here
    vector<int>::iterator i;
    int sum = ((n + 1) * n) / 2;
    for (i = array.begin(); i != array.end(); i++)
    {
        sum = sum - (*i);
    }
    return sum;
}