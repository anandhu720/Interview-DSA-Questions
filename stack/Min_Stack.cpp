/*
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.

*/

//link of Question : https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */


    struct st
    {
        int val;
        int min_so_far;
        st* next;
    };

    st* node;

    MinStack() {
        node=new st();
        node->val=INT_MAX;
        node->min_so_far=INT_MAX;
    }

    void push(int val) {

        st* n=new st();
        n->val=val;
        n->min_so_far=min(val,node->min_so_far);
        n->next=node;
        node=n;

    }

    void pop() {
        node=node->next;
    }

    int top() {
        return node->val;
    }

    int getMin() {
        return node->min_so_far;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
