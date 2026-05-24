class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> s1;
       int left = 0, maxim = 0;

       for (int right = 0; right < s.size(); right++){
            
            if(s1.count(s[right])){
                left = max(left, s1[s[right]] + 1);
            }
            int window_size = right - left + 1;
            s1[s[right]] = right;
            maxim = max(maxim, window_size);
       }
       return maxim;
    }
};