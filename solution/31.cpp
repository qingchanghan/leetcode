/*
 * 版本1
 * 记录的是从后往前的最大值，后来发现只需要找最后一个升序序列即可，见版本2
 */

class Solution {
public:
    void my_reverse(vector<int>& nums, int bg, int ed) {
        int tmp;
        while (bg < ed) {
            tmp = nums[bg];
            nums[bg] = nums[ed];
            nums[ed] = tmp;
            bg++;
            ed--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int i = nums.size()-1;
        int max_index = i, max_num = nums[i];
        int j, tmp;
        /*
            从后往前找第一个比max小的
                如果找到记为left，再从后往前找第一个比left大的，记为right；交换left和right，然后翻转nums[left+1:end]
                如果没找到且当前数比max大，更新max_num和max_index
        */
        for (i--; i >= 0; i--) {
            if (nums[i] < max_num) {
                // 从后往前找第一个比i大的树
                for (j = nums.size()-1; j > i && nums[j] <= nums[i]; j--);
                
                // 交换nums[i]和nums[j]
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                
                // 翻转nums[i+1, end]
                my_reverse(nums, i+1, nums.size()-1);
                
                return;
            } else if (nums[i] > max_num) {
                max_index = i;
                max_num = nums[i];
            }
        }
        
        // 到第一个数也没找到比max小的，翻转整个数组
        my_reverse(nums, 0, nums.size()-1);
        
        return;
    }
};

/*
 * 版本2
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1)
            return;
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

        i++;

        reverse(nums.begin()+i, nums.end());

        return;
    }
};
