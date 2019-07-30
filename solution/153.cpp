class Solution {
public:
    int findMin(vector<int>& nums) {
        int low, high, mid;
        if (nums[0] < nums[nums.size()-1])
            return nums[0];
        
        low = 0;
        high = nums.size()-1;
        // 区间始终保留着最小的数
        while (low < high) {
            mid = (low+high)/2;
            if (nums[mid] > nums[mid+1])
                return nums[mid+1];
            if (nums[mid] > nums[low])
                low = mid;
            else if (nums[mid] < nums[high])
                high = mid;
        }
        
        return nums[low];
    }
};