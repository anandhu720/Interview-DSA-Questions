// Complete the function duplicates() which takes array a[] and n as input as parameters
// and returns a list of elements that occur more than once in the given array in sorted manner.
//  If no such element is found return -1.


vector<int> duplicates(int a[], int n)
{
    vector<int> dup;
    int hash[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (a[i] < n)
            hash[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (hash[i] > 1)
        {
            dup.push_back(i);
        }
    }
    if (!dup.empty())
        return dup;
    else
    {
        dup.push_back(-1);
        return dup;
    }
}
