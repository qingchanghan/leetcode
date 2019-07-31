/*
    二分查找
    log n复杂度
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = (low+high)/2;
            if (nums[mid] > nums[mid+1])
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
/*
    遍历搜索
    线性复杂度
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1 || nums[0] > nums[1])
            return 0;
        if (nums[sz-1] > nums[sz-2])
            return sz-1;
        
        for (int i = 1; i < sz-1; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
            else if (nums[i] > nums[i+1])
                i++;
        }
        return -1;
    }
};