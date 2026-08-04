class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> inter;
        dfs(nums, inter, 0);
        return res;
        
        
    }

private:
vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int>inter, int i) {
        if (i == nums.size()) {
            res.push_back(inter);
            return;
        }
        
        dfs(nums, inter, i+1);
        inter.push_back(nums[i]);
        dfs(nums, inter, i+1);
    }
};
