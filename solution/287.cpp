/*
    龟兔赛跑
    求链表的环起点 O(n)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        
        do {
            p1 = nums[p1];
            p1 = nums[p1];
            p2 = nums[p2];
        } while (p1 != p2);
        
        p1 = 0;
        while (p1 != p2) {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        
        return p1;
    }
};

/*
    naive遍历 O(n^2)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 0; i < sz-1; i++) {
            for (int j = i+1; j < sz; j++) {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
        return -1;
    }
};