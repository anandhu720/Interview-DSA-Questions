/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.
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

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        head = rotate(head, k);
        printList(head);
    }
    return 1;
}

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node *rotate(Node *head, int k)
{
    // Your code here
    Node *p = head;
    Node *q = NULL;
    Node *r = head;
    int key = k;

    if (key == 0)
        return head;
    while (key > 0 && p != NULL)
    {
        q = p;
        r = r->next;
        p = p->next;
        key--;
    }

    if (!p)
        return head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head;
    head = r;
    q->next = NULL;

    return head;
}