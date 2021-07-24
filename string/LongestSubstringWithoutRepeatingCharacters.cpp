/*
 * 
 * 
 * Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


link of question : https://leetcode.com/problems/longest-substring-without-repeating-characters/

*/


// this solution is in O(2n) time and O(n) space

class Solution1{
public:
    int lengthOfLongestSubstring(string s){
        unordered_set<char> hash;
        int l=0,r=0,length=0;
        
        while(r < s.size()){
            
            if(hash.find(s[r]) == hash.end()){
                hash.insert(s[r]);
                length = max(length,r-l+1);
                r++;
            }else{
                hash.erase(s[l]);
                l++;
            }
            
        }
        
        return length;
    }
}

//this solution is in O(n) time comlexity 

class Solution2{
public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char,int> m;
        int l=0,r=0,length=0;
        
        while(r < s.size()){
            
            if(m.find(s[r]) != m.end()){
                if(m.find(s[r])->second+1 > l)
                    l = m.find(s[r])->second+1;
                
                m[s[r]] = r;
                length = max(length,r-l+1);
                r++;
            }
            
            return length;
            
        }
    }
}
