class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        
        int i, j;
        // i - old array index
        // j - new array index
        for (i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                if (i != j)
                    nums[j] = nums[i];
                j++;
            }
        }
        
        return j;
    }
};