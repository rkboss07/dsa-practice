class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m1;
      for (int i = 0; i<nums.size(); i++){
        m1[nums[i]]++;
      }
      priority_queue<pair<int,int>> pq;
      for (const auto& pair : m1) {
        pq.push({pair.second, pair.first});
      }
      vector<int> ans;
      for (int i=0; i < k; i++){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      return ans;
    }
};