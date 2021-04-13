// Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x.
// Find whether element x is present in the matrix or not.

// Input:
// n = 3, m = 3, x = 62
// matrix[][] = {{ 3, 30, 38},
//               {36, 43, 60},
//               {40, 51, 69}}
// Output: 0
// Explanation:
// 62 is not present in the matrix,
// // so output is 0.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        // code here
        int row = 0;
        int col = m - 1;
        while (row < n && col >= 0)
        {
            if (matrix[row][col] == x)
                return 1;
            else if (matrix[row][col] > x)
                col--;
            else
                row++;
        }
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends