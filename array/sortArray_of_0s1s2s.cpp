// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void sort012(int a[], int n)
    {
        // coode here
        int hashTable[3] = {0};
        for (int i = 0; i < n; i++)
            hashTable[a[i]]++;
        int i = 0, j = 0;
        while (i < n)
        {
            if (hashTable[j] != 0)
            {
                a[i++] = j;
                hashTable[j]--;
            }
            else
                j++;
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends