// Given an array of integers. Check whether it contains a triplet that sums up to zero.

// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
bool findTriplets(int arr[], int n);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n] = {0};
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (findTriplets(arr, n))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
} // } Driver Code Ends

/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
//Function to find triplets with zero sum.
bool findTriplets(int arr[], int n)
{
    //Your code here
    int i, j, a;
    // for(i=0;i<n-1;i++)
    // {
    //     for(j=0;j<n-1-i;j++)
    //     {
    //         if(arr[j]>arr[j+1])
    //         {
    //             int temp=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=temp;
    //         }
    //     }
    // }
    sort(arr, arr + n);
    for (a = 0; a < n; a++)
    {
        int b = a + 1;
        int c = n - 1;
        while (b < c)
        {
            if (arr[a] + arr[b] + arr[c] == 0)
                return true;
            else if (arr[a] + arr[b] + arr[c] < 0)
                b++;
            else if (arr[a] + arr[b] + arr[c] > 0)
                c--;
        }
    }
    return false;
}