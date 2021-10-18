/*
 * Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Input:
The first line of input contains an integer denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer n denoting the size of the arrays. In the second line are N space separated values of the array A[].

Output:
For each test case in a new line print the required result.

Constraints:
1 <=T<= 50
1 <=n<= 20
1 <=A[]<= 10000

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

link of question : https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1#

*/

/*Complete the function below*/
int PalinArray(int a[], int n)
{  //add code here.

    for(int i=0;i<n;i++){
        int rev=0;
        int rem=0;
        int copy=a[i];

        while(a[i] != 0){
            rem = a[i]%10;
            rev= rev*10+rem;
            a[i]/=10;
        }

        if(copy != rev)
            return 0;
    }

    return 1;
}
