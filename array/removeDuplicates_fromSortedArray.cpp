// Given a sorted array A of size N, delete all the duplicates elements from A.
// You dont need to read input or print anything. Complete the function remove_duplicate() which takes the array A[]
// and its size N as input parameters and modifies it in place to delete all the duplicates.
// The function must return an integer X denoting the new modified size of the array.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        /*No use of extra space */
        int i = 0;

        for (int j = 1; j < n; j++)
        {
            if (a[j] != a[i])
            {
                i++;
                a[i] = a[j];
            }
        }
        return i + 1;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int n = ob.remove_duplicate(a, N);

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends