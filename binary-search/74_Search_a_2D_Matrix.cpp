class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
            int low = 0, high = matrix.size() * matrix[0].size() - 1;
            int cols = matrix[0].size();
            while(low <= high){
                int mid = low + (high-low)/2;
                
                if (matrix[mid/cols][mid%cols] == target) return true;
                else if (matrix[mid/cols][mid%cols] > target) high = mid-1;
                else low = mid+1;
            }
        
        return false;
    }
};