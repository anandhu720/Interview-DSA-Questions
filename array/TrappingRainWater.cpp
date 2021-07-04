/*
 *
 * Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.


Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10

link of question : https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

*/

#include<bits/stdc++.h>
using namespace std;


int main() {

	//problem input

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//problem solution

	// // METHOD 1

	// // time = o(n ^ 2)
	// // space = o(1)

	// int result = 0;

	// for (int i = 1; i < n - 1; i++) {

	// 	int left = arr[i];
	// 	for (int j = 0; j < i; j++)
	// 		left = max(left, arr[j]);

	// 	int right = arr[i];
	// 	for (int j = i + 1; j < n; j++)
	// 		right = max(right, arr[j]);

	// 	result += min(left, right) - arr[i];

	// }

	// cout << result;

	// METHOD 2

	// time = o(n)
	// space = o(n)

	int left[n];
	int right[n];

	int result = 0;

	left[0] = arr[0];
	for (int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], arr[i]);
	}

	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		right[i] = max(right[i + 1], arr[i]);
	}

	for (int i = 0; i < n; i++) {
		result += min(left[i], right[i]) - arr[i];
	}


	cout << result << endl;



	return 0;
}
