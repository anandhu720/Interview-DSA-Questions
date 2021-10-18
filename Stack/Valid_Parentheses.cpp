/*
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

*/

//link of question : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                char temp = s[i];
                if(st.empty())
                    return false;
                else if(')' == temp && st.top() == '(')
                    st.pop();
                else if(temp == '}' && st.top() == '{')
                    st.pop();
                else if(temp == ']' && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }

        return st.empty()?true:false;
    }
};
