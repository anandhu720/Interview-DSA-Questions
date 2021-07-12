/*
Given a sorted array containing only 0s and 1s, find the transition point. 
*/

int transitionPoint(int arr[], int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            return i;
    }
    return -1;
}
