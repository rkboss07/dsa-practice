class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map <int, int> m1; 
      for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if (!m1.count(complement)){
            m1[nums[i]] = i;
        }
        else {
            return {m1[complement], i};
        }
      }
      return {0};       
    }
};