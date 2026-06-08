class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        if (s1.size() > s2.size()) return false;

        for (char c: s1){
            m1[c]++;
        }
        int left = 0, right = s1.size()-1;
        for (int i = 0; i <= right; i++){
            m2[s2[i]]++;
        }

        while (right < s2.size()-1){
            if (m1==m2) return true;
            
            left++; 
            right++;
            m2[s2[left-1]]--;
            if (m2[s2[left-1]] == 0) m2.erase(s2[left-1]);
            m2[s2[right]]++;
        }
        if (m1==m2) return true;
        return false;
    }
};