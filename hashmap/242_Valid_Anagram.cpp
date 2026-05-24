class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> s1;
        for (char c: s){
            s1[c]++;
        }
        unordered_map<char,int> s2;
        for (char c: t){
            s2[c]++;
        }

        for (auto& pair : s1){
            if (s1[pair.first]!= s2[pair.first]){
                return false;
            }
        }
        return true;
    }
};