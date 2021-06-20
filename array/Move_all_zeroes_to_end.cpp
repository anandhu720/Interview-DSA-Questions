/*
Given an array arr[] of N positive integers. 
Push all the zero’s of the given array to the right end of the array while maitaining the order of non-zero elements.
*/

class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        int count = 0;

        // Traverse the array. If element encountered is non-
        // zero, then replace the element at index 'count'
        // with this element
        for (int i = 0; i < n; i++)
            if (arr[i] != 0)
                arr[count++] = arr[i];

        // Now all non-zero elements have been shifted to
        // front and 'count' is set as index of first 0.
        // Make all elements 0 from count to end.
        while (count < n)
            arr[count++] = 0;
    }
};


