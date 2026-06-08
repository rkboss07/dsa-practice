class Solution {
public:
    bool iscloser(int x, int a, int b) {
        if (abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b))
            return true;
        return false;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == 1)
            return {arr[0]};
        vector<int> ans;
        if (x <= arr[0]) {
            for (int i = 0; i < k; i++)
                ans.push_back(arr[i]);
            return ans;
        }
        if (x >= arr[arr.size() - 1]) {
            for (int i = arr.size() - k; i < arr.size(); i++)
                ans.push_back(arr[i]);
            return ans;
        }
        int left = 0, right = arr.size() - 1;
        while (right - left + 1 > k) {
            if (iscloser(x, arr[left], arr[right]))
                right--;
            else
                left++;
        }
        for (int i = left; i <= right; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};