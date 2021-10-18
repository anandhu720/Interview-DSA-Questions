/*
Given two sorted arrays of distinct elements. 
There is only 1 difference between the arrays. 
First array has one element extra added in between. 
Find the index of the extra element.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int findExtra(int a[], int b[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        cout << findExtra(a, b, n) << endl;
    }
} // } Driver Code Ends

/*Complete the function below*/
int findExtra(int a[], int b[], int n)
{
    // add code here.
    unordered_set<int> s1;
    for (int i = 0; i < n - 1; i++)
        s1.insert(b[i]);
    for (int i = 0; i < n; i++)
    {
        if (s1.find(a[i]) == s1.end())
            return i;
    }
}