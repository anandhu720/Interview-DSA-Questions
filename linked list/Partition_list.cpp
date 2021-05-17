/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 /*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
 
 link of question : "https://leetcode.com/problems/partition-list/"
 
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        ListNode *left = new ListNode(0);
        ListNode *lefthead = left;
        ListNode *right = new ListNode(0);
        ListNode *righthead = right;
        
        while(head != NULL){
            if(head->val < x){
                left->next = head;
                left = head;
                head = head->next;
            }else{
                right->next = head;
                right = head;
                head = head->next;
            }
        }
        left->next = righthead->next;
        right->next = NULL;
        return lefthead->next;
    }
};
