class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low, high, mid;
        vector<int> res(2,-1);
        if (nums.empty())
            return res;
        
        int sz = nums.size();
        // 第一遍找比target小的最大的数
        low = 0;
        high = sz - 1;
        while (low < high) {
            mid = (low+high+1)/2;
            if (nums[mid] >= target) {
                high = mid-1;
            } else {
                low = mid;
            }
        }
        if (nums[low] == target)
            res[0] = 0;
        else if (low+1 < sz && nums[low+1] == target)
            res[0] = low+1;
        
        if (res[0] == -1) {
            res[1] = -1;
            return res;
        }
        
        // 第二遍找比target大的最小的数
        low = res[0];
        high = sz - 1;
        while (low < high) {
            mid = (low+high)/2;
            if (nums[mid] <= target)
                low = mid+1;
            else
                high = mid;
        }
        if (nums[high] == target)
            res[1] = high;
        else
            res[1] = high - 1;
            
        return res;
    }
};