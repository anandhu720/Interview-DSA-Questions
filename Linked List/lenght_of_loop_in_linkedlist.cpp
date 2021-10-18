/*
Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given 
Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. 
C is the position of the node to which the last node is connected.
If it is 0 then no loop.
*/

// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

int countNodesinLoop(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        cout << countNodesinLoop(head) << endl;
    }
    return 0;
}
// } Driver Code End

// Your task is to complete the function this function
// function should return the size of the loop

int countNodesinLoop(struct Node *head)
{
    // Code here
    struct Node *p = head;
    struct Node *q = head;

    if (p == NULL)
        return NULL;

    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
            q = q->next;
    } while (p && q && p != q);
    if (p == q)
    {
        struct Node *temp = q;
        int lenght = 1;
        while (temp->next != q)
        {
            lenght++;
            temp = temp->next;
        }
        return lenght;
    }
    return 0;
}