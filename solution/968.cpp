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