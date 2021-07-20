/*
Your Task:
You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size N as input parameters and return the index of any one of its peak elements.

Can you solve the problem in expected time complexity?

 

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

link of question : https://practice.geeksforgeeks.org/problems/peak-element/1

*/

// native sol
// o(n) time

// class Solution
// {
//     public:
//     int peakElement(int arr[], int n)
//     {
//       // Your code here
//       if(n==1){
//           return 0;
//       }
       
//       if(arr[0] > arr[1])
//             return 0;
//         if(arr[n-1]>arr[n-2])
//             return n-1;
            
//         for(int i=1;i<n-1;i++){
//             if(arr[i]>arr[i+1] && arr[i] > arr[i-1])
//                 return i;
//         }
//     }
// };

// efficent sol
// o(logN) time

class Solution
{
    public:
    int findPeak(int arr[],int l,int h,int n){
        
        int mid = (l+h)/2;
        
        if((mid==0 || arr[mid-1]<=arr[mid]) &&(mid == n-1 || arr[mid+1] <= arr[mid]))
            return mid;
        else if(mid>0 && arr[mid-1] >arr[mid] )
            return findPeak(arr,l,mid-1,n);
        else
            return findPeak(arr,mid+1,h,n);
    }
    
    int peakElement(int arr[], int n)
    {
        return findPeak(arr,0,n-1,n);
    }
    
};

