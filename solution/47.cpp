/*
 * 有重复元素
 * 还是用字典序方法，每次调用nextPermutation
 * STL中自带了next_permutation()方法
 */
class Solution {
public:
    
    bool nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1)
            return false;
        int i, j;
        
        /*
            从后往前找第一个升序序列
                如果找到记为left，再从后往前找第一个比left大的，记为right；交换left和right，然后翻转nums[left+1:end]
            如果到最后都没找到，翻转整个数组
        */
        for (i = sz-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                // 从后往前找第一个比i大的树
                for (j = sz-1; j > i && nums[j] <= nums[i]; j--);
                
                // 交换nums[i]和nums[j]
                swap(nums[i], nums[j]);
                
                break;
            }
        }
        
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return false;
        }
        
        i++;
        
        reverse(nums.begin()+i, nums.end());
        
        return true;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> final_result;
        bool flag;
        
        sort(nums.begin(), nums.end(), less<int>());
        final_result.push_back(nums);
        while(1) {
            flag = nextPermutation(nums);
            
            if (flag)
                final_result.push_back(nums);
            else
                break;
        }
        
        return final_result;
    }
};
