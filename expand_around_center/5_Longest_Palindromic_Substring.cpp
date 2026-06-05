class Solution {
public:
    int expand_from_center(string s, int right, int left){
        while(left >= 0 && right < s.size() && s[right] == s[left]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        if (s.size() == 0) return s;
        int start = 0,max_len = 0;
        for (int i=0; i<s.size(); i++){
            int len1 = expand_from_center(s,i,i);
            int len2 = expand_from_center(s,i,i+1);

            int current_max = max(len1,len2);
            if (current_max > max_len) {
                max_len = current_max;
                start = i - (max_len-1)/2;
            }
        }
        
        string ans = "";
        for (int i = start; i < start + max_len; i++) ans.push_back(s[i]);
        return ans;
    }
};