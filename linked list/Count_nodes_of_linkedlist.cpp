/*
Given a singly linked list.
The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
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

int getCount(struct Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout << getCount(head) << endl;
    }
    return 0;
} // } Driver Code Ends

// head : reference to head of linked list
int getCount(struct Node *head)
{

    //Code here
    if (head == nullptr)
        return NULL;
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
