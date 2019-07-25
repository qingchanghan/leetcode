class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        
        int i, j;
        // i old array
        // j new array
        /*
        for (i = 1, j = 1; i < sz; i++) {
            if (nums[i] != nums[i-1]) {
                if (i != j)
                    nums[j] = nums[i];
                j++;
            } else {
                do{
                    i++;
                }while(i < sz && nums[i] == nums[i-1]);
                i--;
            }
        }*/
        
        for (i = 1, j = 1; i < sz; i++) {
            if (nums[i] != nums[i-1])
                nums[j++] = nums[i];
        }
        
        return j;
    }
};