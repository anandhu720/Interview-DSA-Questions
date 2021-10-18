/*
 *
 * Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.



Example 1:

Input:
Circular LinkedList: 1->5->7
Output:
1 5
7


Example 2:

Input:
Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

link of question : https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#

*/

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if(head == NULL)
        return;

    /* If there are odd nodes in the circular list then
       fast_ptr->next becomes head and for even nodes
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head &&
          fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    /* Set the head pointer of first half */
    *head1_ref = head;

    /* Set the head pointer of second half */
    if(head->next != head)
        *head2_ref = slow_ptr->next;

    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;

    /* Make first half circular */
    slow_ptr->next = head;

}
