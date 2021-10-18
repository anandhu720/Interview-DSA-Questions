// Given an array of integers. Check whether it contains a triplet that sums up to zero.


//Function to find triplets with zero sum.
bool findTriplets(int arr[], int n)
{
    //Your code here
    int i, j, a;
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
