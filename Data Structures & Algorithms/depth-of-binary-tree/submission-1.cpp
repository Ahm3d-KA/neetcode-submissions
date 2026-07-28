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
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int res = 0;

        while (!s.empty()) {
            auto [node, d] = s.top(); s.pop();
            if (node) {
                res = max(res, d);
                s.push({node->left, d+1});
                s.push({node->right, d+1});
            }
        }
        return res;
        
    }
};
