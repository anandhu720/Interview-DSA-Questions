/*
 *
 * Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is 6, -3, -10 which gives product as 180.

Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is 2, 3, 4, 5 which gives product as 120.


link of question : https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

*/

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long ma = arr[0];
	    long long mi = arr[0];

	    long long product = arr[0];

	    for(int i=1;i<n;i++){

	        if(arr[i]<0)
	            swap(ma,mi);

	        ma = max((long long)arr[i],ma*arr[i]);
	        mi = min((long long)arr[i],mi*arr[i]);

	        if(ma>product)
	            product=ma;
	    }

	    return product;

	}
};

