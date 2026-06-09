class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, window_size = 1; 
        long long remainingSteps = k;
        for (int right = 1; right<nums.size(); right++){
            
            remainingSteps -= (long long)(nums[right]-nums[right-1])*(right-left);
            
            while (remainingSteps < 0){
                remainingSteps+= nums[right] - nums[left];
                left++;
            }
            window_size=max(window_size, right - left + 1);
        }
        return window_size;
    }
};