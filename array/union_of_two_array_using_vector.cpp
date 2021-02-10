/*
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size N and M respectively, find their union.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    unordered_set<int> s1;
    vector<int> g1;
    for (int i = 0; i < n; i++)
        s1.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s1.insert(arr2[i]);
    unordered_set<int>::iterator itr;
    for (itr = s1.begin(); itr != s1.end(); itr++)
        g1.push_back(*itr);
    sort(g1.begin(), g1.end());

    return g1;
}

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }

        vector<int> ans = findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
} // } Driver Code Ends