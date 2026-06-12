class Solution {
public:
    int longestValidParentheses(string s) {
       stack<int> s1;
       s1.push(-1);
       int maxLen = 0;
       for (int i = 0; i<s.size();i++){
        
        if (s[i] == ')' && !s1.empty() && s1.top() != -1 && s[s1.top()] == '(') s1.pop();
        else s1.push(i);
        maxLen = max(maxLen, i-s1.top());
        }        
        
        return maxLen;
    }
};