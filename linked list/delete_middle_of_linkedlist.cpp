/*
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 
then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. 
For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL
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

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
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
        head = deleteMid(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends

// Deletes middle of linked list and returns head of the modified list
Node *deleteMid(Node *head)
{
    // Your Code Here
    Node *p = head;
    Node *q = head;
    Node *tail = NULL;

    while (q->next != NULL)
    {
        tail = p;
        p = p->next;
        q = q->next;
        if (q->next != NULL)
            q = q->next;
    }
    tail->next = p->next;
    delete p;

    return head;
}