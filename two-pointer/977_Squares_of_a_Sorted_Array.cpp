class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sq(nums.size());

        for (int i = 0; i < nums.size(); i++){
            nums[i] = nums[i]*nums[i];
        }

        int left = 0, right = sq.size()-1, last_place = sq.size()-1;

        while (left <= right) {
            if (nums[left] > nums[right]){
                sq[last_place] = nums[left];
                left++;
            }
            else {
                sq[last_place] = nums[right];
                right--;
            }
            last_place--;
        }
        return sq;
    }
};