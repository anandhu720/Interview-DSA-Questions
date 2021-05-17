/*
 You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

*/

// Link of Question : https://leetcode.com/problems/reorder-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *p = head;
        if(head == NULL || head->next == NULL  || head->next->next == NULL)
            return;
        stack<ListNode *> s;
        int n=0;

        while(p!=NULL){
            n++;
            s.push(p);
            p=p->next;
        }
        p=head;
        for(int i=0;i<n/2;i++){
            ListNode *temp = s.top();
            s.pop();
            temp->next = p->next;
            p->next = temp;
            p=p->next->next;
        }
        p->next = NULL;
    }
};
