class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left, right, min;
        int sz = nums.size();
        if (nums[0] <= nums[nums.size()-1]) {
            left = 0;
            right = sz-1;
        } else {
            // 先找最小的数的下标
            int low = 0;
            int high = nums.size()-1;
            while (low < high) {
                int mid = (low+high)/2;
                if (nums[mid] > nums[mid+1]) {
                    min = mid+1;
                    break;
                }
                if (nums[mid] > nums[low])
                    low = mid;
                else
                    high = mid;
            }
            
            if (target < nums[min] || target > nums[min-1])
                return -1;
            if (target <= nums[sz-1]) {
                left = min;
                right = sz-1;
            } else if (target >= nums[0]) {
                left = 0;
                right = min-1;
            } else
                return -1;
        }
        
        while (left <= right) {
            int mid = (left+right)>>1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        
        return -1;
    }
};