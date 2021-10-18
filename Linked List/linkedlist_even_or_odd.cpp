/*

Given a linked list of size N,
your task is to complete the function isLengthEvenOrOdd() which contains head of the linked list
and check whether the length of linked list is even or odd.

*/

// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to check the length of linklist
int isLengthEvenOrOdd(struct Node *head);

// Driver function
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tmp, first, i, l;
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> first;
        head = new Node(first);
        tail = head;
        for (i = 0; i < n - 1; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        if (isLengthEvenOrOdd(head) == 0)
            cout << "Even\n";
        else
            cout << "Odd\n";
    }
    return 0;
}

// } Driver Code Ends

// Function should return 0 is length is even else return 1
int isLengthEvenOrOdd(struct Node *head)
{
    //Code here
    int count = 0;
    if (head == NULL)
        return NULL;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    if (count % 2 == 0)
        return 0;
    else
        return 1;
}