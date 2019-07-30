class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty() || matrix[0][0] > target)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n-1, mid, num;
        
        while (low <= high) {
            mid = (low+high)/2;
            num = matrix[mid/n][mid%n];
            if (num == target)
                return true;
            else if (num < target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return false;
    }
};