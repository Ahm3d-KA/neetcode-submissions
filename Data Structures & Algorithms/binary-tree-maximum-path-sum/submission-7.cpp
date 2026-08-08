/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int res = INT_MIN;
    int dfs (TreeNode* cur) {
        if (!cur) return 0;
        int r = dfs(cur->right);
        int l = dfs(cur->left);
        int nosplit = max(r, l);
        res = max(res, cur->val + r + l);
        res = max(res, nosplit + cur->val);
        if (nosplit + cur->val < 0) return 0;
        return nosplit + cur->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int r = dfs(root);
        // return max(res, r);
        return res;
    }
};
