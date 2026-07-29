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
    pair<bool, int> balance(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }
        auto [bl, hl] = balance(root->left);
        auto [br, hr] = balance(root->right);
        if (abs(hl - hr) <= 1) {
            return {(bl && br), max(hl, hr) + 1};
        }
        return {false, -1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return balance(root).first;
        
    }
};
