/*
Given a sorted singly linked list and a data, your task is to insert the data in the linked list in a sorted way 
i.e. order of the list doesn't change.
*/

// { Driver Code Starts
//

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

Node *sortedInsert(struct Node *head, int data);

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

        int k;
        cin >> k;

        head = sortedInsert(head, k);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends

// Should return head of the modified linked list
Node *sortedInsert(struct Node *head, int data)
{
    // Code here
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return head;
    }

    if (data < head->data)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL && p->next->data < data)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }

    return head;
}