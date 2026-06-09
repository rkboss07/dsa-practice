class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZero = 0, left = 0;
        int maxWindow = 0;
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0) countZero++;
            while (countZero > k){
                if (nums[left] == 0) countZero--;
                left++;
            }
            maxWindow = max(maxWindow, right-left+1);
        }
        return maxWindow;
    }
};