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
 int withMax(TreeNode* root, int max) {
    if (!root) return 0;
    if (root->val >= max) {
        return 1 + withMax(root->right, root->val)
        + withMax(root->left, root->val);
    }
    return withMax(root->right, max)
    + withMax(root->left, max);
 }
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return withMax(root, root->val);
        
    }
};
