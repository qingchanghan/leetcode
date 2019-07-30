class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty() || matrix[0][0] > target)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        if (matrix[m-1][n-1] < target)
            return false;
        
        // 从左下角开始
        int curx = m-1, cury = 0, num;
        
        while (curx >= 0 && cury <= n-1) {
            num = matrix[curx][cury];
            if (num == target)
                return true;
            else if (num > target)
                curx--;
            else
                cury++;
        }
        
        return false;
    }
};