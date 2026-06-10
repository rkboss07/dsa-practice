class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m1;
        int streak = 0;
        for (int i = 0; i < nums.size(); i++) {
            m1.insert(nums[i]);
        }
        for (auto n : m1) {
            if (!m1.count(n - 1)) {
                int cur = n, streak_cur = 0;
                while (m1.count(cur)) {
                    streak_cur++;
                    cur++;
                }
                streak = max(streak, streak_cur);
            }
        }
        return streak;
    }
};