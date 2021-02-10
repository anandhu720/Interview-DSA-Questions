/*
Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 
in o(n) time
*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

void rotateArr(int arr[], int d, int n)
{
    // code here
    int i, j;
    for (i = 0, j = d - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int i = d, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    //taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;

        //input n and d
        cin >> n >> d;

        int arr[n];

        //inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        //calling rotateArr() function
        rotateArr(arr, d, n);

        //printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends