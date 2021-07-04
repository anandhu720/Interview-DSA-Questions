/*
 *
 * Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8.

link of question : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#

*/


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node *p =head;
       int count = 0;
       while(p!=NULL){
           count++;
           p=p->next;
       }

       p=head;

       if(n > count)
            return -1;

       int actual_length = count-n;

       while(actual_length >0 && p!=NULL){
           p=p->next;
           actual_length--;
       }

       return p->data;
}


