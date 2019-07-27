/*
 * 迭代解法 16ms
 */
class Solution {
public:
    
    void recursion(vector<int> cur_nums, set<int> cur_set, vector<vector<int>>& final_result) {
        if (cur_set.empty()) {
            final_result.push_back(cur_nums);
        }
        
        set<int> tmp(cur_set.begin(), cur_set.end());
        set<int>::iterator it;
        for (it = cur_set.begin(); it != cur_set.end(); it++) {
            tmp.erase(*it);
            cur_nums.push_back(*it);
            
            recursion(cur_nums, tmp, final_result);
            
            cur_nums.pop_back();
            tmp.insert(*it);
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> final_result;
        vector<int> cur_nums;
        set<int> all_num(nums.begin(), nums.end());
        
        recursion(cur_nums, all_num, final_result);
        
        return final_result;
    }
};

/*
 * 字典序，下一个permutation 12ms
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> final_result;
        
        // 计算排列数目
        long count = 1;
        for (int i = 2; i <= nums.size(); i++)
            count *= i;
        
        final_result.push_back(nums);
        for (long i = 1; i < count; i++) {
            nextPermutation(nums);
            final_result.push_back(nums);
        }
        
        return final_result;
    }
};

/*
 * 邻位对换法 12ms
 */
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> final_result;
        int sz = nums.size();
        long count = 1;
        for (int i = 1; i <= sz; i++)
            count *= i;

        int* dir= new int[sz];  //存储方向，0为向左，1为向右
        for (int i = 0; i < sz; i++)
            dir[i] = 0;


        // 升序排列
        sort(nums.begin(), nums.end(), less<int>());
        final_result.push_back(nums);

        int max_index, max_num;

        for (long i = 1; i < count; i++) {
            max_num = INT_MIN;
            for (int j = 0; j < sz; j++) {
                // 0：向左
                if (((dir[j] == 0 && j > 0 && nums[j-1] < nums[j]) ||
                    (dir[j] == 1 && j < sz-1 && nums[j+1] < nums[j])) && nums[j] > max_num) {
                    max_num = nums[j];
                    max_index = j;
                }
            }

            if (max_num == INT_MIN)
                break;
            else {
                if (dir[max_index] == 0) {
                    swap(nums[max_index-1], nums[max_index]);
                    swap(dir[max_index-1], dir[max_index]);
                }
                else {
                    swap(nums[max_index+1], nums[max_index]);
                    swap(dir[max_index+1], dir[max_index]);
                }

                for (int j = 0; j < sz; j++) {
                    if (nums[j] > max_num)
                        dir[j] = 1 - dir[j];
                }
            }

            final_result.push_back(nums);
        }

        return final_result;
    }
};

/*
 * 递归法，不用额外的空间 8ms
 */
class Solution {
public:

    void fullarrange(vector<int>& nums, int size, int begin, vector<vector<int>>& result){
        if (begin == size){
            result.push_back(nums);
            return;
        }

        for (int i=begin; i<size; ++i){
            swap(nums[i], nums[begin]);
            fullarrange(nums, size, begin+1, result);
            swap(nums[i], nums[begin]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> final_result;

        fullarrange(nums, nums.size(), 0, final_result);

        return final_result;
    }
};
