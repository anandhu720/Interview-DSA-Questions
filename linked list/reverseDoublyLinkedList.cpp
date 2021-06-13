/*
 *
 * Given a doubly linked list of n elements. The task is to reverse the doubly linked list.

Example 1:

Input:
LinkedList: 3 <--> 4 <--> 5
Output: 5 4 3
Example 2:

Input:
LinkedList: 75 <--> 122 <--> 59 <--> 196
Output: 196 59 122 75

link of question : https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1#

*/

Node* reverseDLL(Node * head)
{
    //Your code here
    Node* temp = nullptr;
    Node* current = head;

    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current=current->prev;
    }

    if(temp != NULL)
        head=temp->prev;

    return head;
}

