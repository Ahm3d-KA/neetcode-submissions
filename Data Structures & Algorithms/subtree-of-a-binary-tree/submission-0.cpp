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
    bool sameTree(TreeNode* t, TreeNode* u) {
        if (!t && !u) {
            return true;
        }
        if (!t || !u) {
            return false;
        }
        if (t->val == u->val) {
            return sameTree(t->left, u->left) && sameTree(t->right, u->right);
        }
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (!subRoot) {
            return true;
        }
        if (!sameTree(root, subRoot)) {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        return true;

        
    }
};
