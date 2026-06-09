class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> m1, m2;
        for (char c : t)
            m1[c]++;

        int need = m1.size();
        int have = 0;
        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        for (int right = 0; right < s.size(); right++) {
            if (m1.count(s[right]))
                m2[s[right]]++;
            if (m1.count(s[right]) && m2[s[right]] == m1[s[right]])
                have++;
            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                if (m1.count(s[left]) && m2[s[left]] == m1[s[left]])
                    have--;
                m2[s[left]]--;
                left++;
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";
    }
};