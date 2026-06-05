class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            int current_max = 0;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }             
            }

        }
        int maxim = dp[0];
        for (int i = 1; i < dp.size(); i++){
            maxim = max(dp[i], maxim);
        }
        return maxim;
        
    }
};