/*
    vector作返回值
    20ms
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> recursive(TreeNode* root) {
        vector<int> result = {9999, 0, 0};
        // result[0]代表root节点有camera时的最小值
        // result[1]代表root节点没有camera时的最小值
        // result[2]代表root节点不会被监视时的最小值（即root的子节点不能有camera）
        if (root != NULL) {
            vector<int> left_result = recursive(root->left);
            vector<int> right_result = recursive(root->right);
            int minL01 = min(left_result[0], left_result[1]);
            int minR01 = min(right_result[0], right_result[1]);
            
            result[0] = min(minL01, left_result[2]) + min(minR01, right_result[2]) + 1;
            result[1] = min(left_result[0]+minR01, right_result[0]+minL01);
            result[2] = left_result[1] + right_result[1];
        }
        return result;
    }
    
    int minCameraCover(TreeNode* root) {
        vector<int> result = recursive(root);
        return min(result[0], result[1]);
    }
};

/*
    int引用传值
    12ms
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void recursive(TreeNode* root, int& r0, int& r1, int &r2) {
        // result[0]代表root节点有camera时的最小值
        // result[1]代表root节点没有camera时的最小值
        // result[2]代表root节点不会被监视时的最小值（即root的子节点不能有camera）
        if (root != NULL) {
            int l_r0, l_r1, l_r2, r_r0, r_r1, r_r2;
            recursive(root->left, l_r0, l_r1, l_r2);
            recursive(root->right, r_r0, r_r1, r_r2);
            
            int minL01 = min(l_r0, l_r1);
            int minR01 = min(r_r0, r_r1);
            
            r0 = min(minL01, l_r2) + min(minR01, r_r2) + 1;
            r1 = min(l_r0+minR01, r_r0+minL01);
            r2 = l_r1 + r_r1;
        } else {
            r0 = 9999;
            r1 = 0;
            r2 = 0;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int r0, r1, r2;
        recursive(root, r0, r1, r2);
        return min(r0, r1);
    }
};

/*
    贪心算法 20ms
    - 如果一个节点的孩子都覆盖了，而且他有parent，那就在他的parent放camera
    - 如果一个节点有孩子没被覆盖，那就在这放一个camera
    - 如果一个节点没有parent，且他没有被覆盖，那就在这放一个camera
 */
class Solution {
public:
    
    int res;
    set<TreeNode*> covered;
    
    void dfs(TreeNode* root, TreeNode* parent) {
        if (root != NULL) {
            dfs(root->left, root);
            dfs(root->right, root);
            
            if ((parent == NULL && covered.find(root) == covered.end()) ||
                    covered.find(root->left) == covered.end() ||
                    covered.find(root->right) == covered.end()) {
                res++;
                covered.insert(parent);
                covered.insert(root);
                covered.insert(root->left);
                covered.insert(root->right);
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        res = 0;
        covered.insert(NULL);
        
        dfs(root, NULL);
        return res;
    }
};

/*
    大神的贪心法
    - 在所有叶子节点的parent处放置camera
    - 对于叶节点返回0，对于叶节点的parent返回1，已经覆盖的节点返回2（相当于NULL）
 */
class Solution {
public:
    
    int res = 0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};