/*
    reference: 
        https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
*/
class Solution {
public:
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size(), n = nums2.size();
        vector<int> *A = &nums1, *B = &nums2;
        
        if (m > n) {
            A = &nums2;
            B = &nums1;
            m = (*A).size();
            n = (*B).size();
        }
        
        int i, j, max_left, min_right;
        int imin = 0, imax = m;
        
        // i: m+1 kinds of cutting
        // j: n+1 kinds of cutting
        while (imin <= imax) {
            i = (imin+imax) / 2;
            j = (m+n+1)/2 - i;
            
            if (i < m && (*B)[j-1] > (*A)[i]) {
                // i too small, increase i
                imin = i+1;
            } else if (i > 0 && (*A)[i-1] > (*B)[j]) {
                // i too big, decrease i
                imax = i-1;
            } else {
                // found right i
            
                if (i == 0)
                    max_left = (*B)[j-1];
                else if (j == 0)
                    max_left = (*A)[i-1];
                else
                    max_left = max((*B)[j-1], (*A)[i-1]);
                
                if ((m+n) % 2 == 1)
                    return max_left;
                
                if (i == m)
                    min_right = (*B)[j];
                else if (j == n)
                    min_right = (*A)[i];
                else
                    min_right = min((*B)[j], (*A)[i]);
                
                return (max_left+min_right)/2.0;
            }
            
        }
        
        return 0.0;
    }
};