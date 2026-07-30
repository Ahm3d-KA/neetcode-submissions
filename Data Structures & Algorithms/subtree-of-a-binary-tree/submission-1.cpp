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
    string serialise(TreeNode* root) {
        if (!root) {
            return "#";
        }
        string v = "$";
        v += to_string(root->val);
        return v + serialise(root->left) + serialise(root->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string sr, ss, com;
        sr = serialise(root);
        ss = serialise(subRoot);
        com = ss + "|" + sr;
        vector<int> res(com.length());
        int j;
        for (int i=0; i<com.length(); i++) {
            j=0;
            while (com[i+j] == com[0+j] && i+j < com.length()) {
                j++;
                res[i]++;
            } 
            if (res[i] == ss.length()) {
                return true;
            }
        }
        return false;

        
        
        
        
    }
};
