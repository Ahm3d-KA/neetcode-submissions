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
        if (!root) return true;
        unordered_map<TreeNode*, pair<bool, int>> m;
        m[nullptr] = {true, 0};
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* node;
        while (!s.empty()) {
            node = s.top();
            if (node->right && m.find(node->right) == m.end()) {
                s.push(node->right);
            }
            else if (node->left && m.find(node->left) == m.end()) {
                s.push(node->left);
            }
            else {
                node = s.top(); s.pop();
                auto [bl, hl] = m[node->left];
                auto [br, hr] = m[node->right];
                if (abs(hl - hr) <= 1) {
                    m[node] = {(bl && br), max(hl, hr) + 1};
                }
                else {
                    return false;
                }
            }
            

        }
        return m[root].first;
        
    }
};
