/*
    为输入的所有节点构建一个图，如果两个节点加起来是完全平方数，则这两个节点之间存在一条边
    只需要寻找哈密顿路径的数目即可，使用dfs
    8ms
 */
class Solution {
public:
    
    bool isSquare(int n) {
        for (int i = 1; n > 0; i+=2)
            n -= i;
        if (n == 0)
            return true;
        else
            return false;
    }
    
    int dfs(int x, int rest, map<int, set<int>>& graph, map<int, int>& count) {
        int result = 1;
        
        count[x]--;
        
        if (rest != 0) {
            result = 0;
            
            if (graph.find(x) != graph.end()) {
                for (set<int>::iterator it = graph[x].begin(); it != graph[x].end(); it++) {
                    if (count[*it] > 0)
                        result += dfs(*it, rest-1, graph, count);
                }
            }
        }
        
        count[x]++;
        return result;
    }
    
    int numSquarefulPerms(vector<int>& A) {
        map<int, set<int>> graph;
        map<int, int> count;
        int result = 0;
        int sz = A.size();
        
        for (int i = 0; i < sz; i++) {
            if (count.find(A[i]) != count.end()) {
                count[A[i]]++;
            } else {
                count[A[i]] = 1;
            }
        }
        
        for (int i = 0; i < sz; i++) {
            for (int j = i+1; j < sz; j++) {
                if (isSquare(A[i]+A[j])) {
                    if (graph.find(A[i]) != graph.end()) {
                        graph[A[i]].insert(A[j]);
                    } else {
                        set<int> tmp;
                        tmp.insert(A[j]);
                        graph[A[i]] = tmp;
                    }
                    
                    if (graph.find(A[j]) != graph.end()) {
                        graph[A[j]].insert(A[i]);
                    } else {
                        set<int> tmp;
                        tmp.insert(A[i]);
                        graph[A[j]] = tmp;
                    }
                }
            }
        }
        
        for (map<int, set<int>>::iterator it = graph.begin(); it != graph.end(); it++) {
            result += dfs(it->first, sz-1, graph, count);
        }
        
        return result;
    }
};

/*
    大佬的100%算法
    （感觉也没什么区别...
    0ms
 */
class Solution {
private:
    bool check(long long n1, long long n2) {
        long long n = n1 + n2;
        long long low = 0;
        long long high = n;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid * mid == n) return true;
            if(mid * mid < n) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

    int dfs(vector<vector<int>>& graph, vector<pair<int, int>>& nums, int curr, int total) {
        if(total == 0) return 1;
        int res = 0;
        for(int next : graph[curr]) {
            if(nums[next].second == 0) continue;
            nums[next].second--;
            res += dfs(graph, nums, next, total - 1);
            nums[next].second++;
        }
        return res;
    }
public:
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> counter;
        for(int i : A) counter[i]++;
        vector<pair<int, int>> nums(counter.begin(), counter.end());
        int size = nums.size();
        vector<vector<int>> graph(size);
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(check(nums[i].first, nums[j].first)) graph[i].push_back(j);
            }
        }
        int res = 0;
        for(int i = 0; i < size; i++) {
            if(nums[i].second == 0) continue;
            nums[i].second--; 
            res += dfs(graph, nums, i, A.size() - 1);
            nums[i].second++;
        }
        return res;
    }
};