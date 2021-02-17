/*
Given two sorted arrays A and B of size M and N respectively. 
Each array contains only distinct elements but may have some elements in common with the other array. 
Find the maximum sum of a path from the beginning of any array to the end of any of the two arrays. 
We can switch from one array to another array only at the common elements.
Note: Only one repeated value is considered in the valid path sum.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int max_path_sum(int[], int[], int, int);

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        int result = max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

// } Driver Code Ends

/*You are required to complete this method*/
int max_path_sum(int A[], int B[], int l1, int l2)
{
    int sum1 = 0;
    int sum2 = 0;
    int result = 0;
    int i = 0, j = 0;
    while (i < l1 && j < l2)
    {
        if (A[i] < B[j])
        {
            sum1 += A[i++];
        }
        else if (B[j] < A[i])
        {
            sum2 += B[j++];
        }
        else if (A[i] == B[j])
        {
            result += max(sum1, sum2);
            sum1 = 0, sum2 = 0;
            while (i < l1 && j < l2 && A[i] == B[j])
            {
                result += A[i++];
                j++;
            }
        }
    }
    for (; i < l1; i++)
        sum1 += A[i];
    for (; j < l2; j++)
        sum2 += B[j];
    result += max(sum1, sum2);
    return result;

    //Your code here
}