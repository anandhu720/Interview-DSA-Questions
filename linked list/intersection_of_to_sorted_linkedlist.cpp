/*
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. 
The new list should be made with its own memory — the original lists should not be changed.
*/

// { Driver Code Starts
//

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

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here

    unordered_set<int> l1;

    Node *p = head1;
    Node *q = head2;
    Node *head3 = NULL;
    Node *rev = NULL;

    while (p != NULL)
    {
        l1.insert(p->data);
        p = p->next;
    }

    while (q != NULL)
    {
        if (l1.find(q->data) != l1.end())
        {
            Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = q->data;
            temp->next = NULL;
            if (rev == NULL)
            {
                head3 = temp;
                rev = temp;
            }
            else
            {
                rev->next = temp;
                rev = temp;
            }
            l1.erase(q->data);
        }
        q = q->next;
    }

    return head3;
}