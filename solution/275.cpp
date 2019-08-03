class Solution {
public:
    
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int sz = citations.size();
        int low = 0, high = citations[sz - 1];
        
        while (low < high) {
            int mid = low + (high - low + 1)/2;
            if (sz >= mid && citations[sz-mid] >= mid)
                low = mid;
            else
                high = mid - 1;
        }
        
        return low;
    }
};