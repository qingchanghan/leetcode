/*
    二分搜索
    注意上下界的取值
    本题要求向下取整，所以low不能等于mid-1
 */
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int mid;
        
        while (low < high) {
            mid = low + (high - low) / 2 + 1;
            if (mid <= x/mid)
                low = mid;
            else
                high = mid-1;
        }
        
        return low;
    }
};


class Solution {
public:
    int mySqrt(int x) {
        return (int)sqrt(x);
    }
};