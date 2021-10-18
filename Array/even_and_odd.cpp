/*
Given an array arr[] of size N containing equal number of odd and even numbers. 
Arrange the numbers in such a way that all the even numbers get the even index and odd numbers get the odd index.
Note: There are multiple possible solutions, Print any one of them. Also, 0-based indexing is considered.
*/



class Solution
{
public:
    void reArrange(int arr[], int N)
    {
        // code here
        int i = 0, j = 1;
        while (i < N && j < N)
        {
            if (arr[i] % 2 != 0 && arr[j] % 2 == 0)
            {
                swap(&arr[i], &arr[j]);
                i += 2;
                j += 2;
            }
            else if (arr[i] % 2 == 0)
                i = i + 2;
            else if (arr[j] % 2 != 0)
                j = j + 2;
        }
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

