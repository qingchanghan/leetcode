// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (isBadVersion(1))
            return 1;
        if (!isBadVersion(n))
            return n;
        
        int low = 1, high = n;
        while (low < high) {
            int mid = low+(high-low+1)/2;
            if (isBadVersion(mid))
                high = mid-1;
            else
                low = mid;
        }
        return low+1;
    }
};