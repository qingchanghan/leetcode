class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        
        int i, j;
        int cache = INT_MAX;
        
        for (i = 2, j = 2; i < nums.size(); i++) {
            if (nums[i] != nums[i-2]) {
                if (cache != INT_MAX) {
                    nums[j++] = cache;
                }
                cache = nums[i];
            }
        }
        if (cache != nums[j-2] && cache != INT_MAX)
            nums[j++] = cache;
        
        return j;
    }
};

// 大于号 比 不等于号 快
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        
        int i, j;
        
        for (i = 2, j = 2; i < nums.size(); i++) {
            if (nums[i] > nums[j-2]) {
                nums[j++] = nums[i];
            }
        }
        
        return j;
    }
};