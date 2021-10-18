/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such 
that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.
*/

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
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

struct Node *start = NULL;

struct Node *segregate(struct Node *head);

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
} // } Driver Code Ends

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node *segregate(Node *head)
{

    // Add code here
    Node *p = head;
    if (p == NULL)
        return NULL;

    int arr[3] = {0, 0, 0};
    while (p != NULL)
    {
        arr[p->data]++;
        p = p->next;
    }

    p = head;
    int i = 0;

    while (p != NULL)
    {
        if (arr[i] == 0)
            i++;
        else
        {
            p->data = i;
            arr[i]--;
            p = p->next;
        }
    }

    return head;
}
