class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m1;
        for (int i = 0; i < strs.size(); i++){
            string initial_string = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m1[strs[i]].push_back(initial_string);
        }
        vector<vector<string>> ans;
        for (const auto& pair: m1){
            ans.push_back(pair.second);
        }
        return ans;
    }
};