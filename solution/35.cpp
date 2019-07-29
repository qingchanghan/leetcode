class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        if (nums[high] < target)
            return high+1;
        if (nums[0] > target)
            return 0;
        
        while (low < high) {
            int mid = (low+high)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                high = mid;
            else
                low = mid+1;
        }
        
        return low;
    }
};