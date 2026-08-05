class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> inter;
        this->target = target;
        dfs(nums, inter, 0, 0);
        return res;
        
    }
private:
    int target;
    vector<vector<int>> res;
    void dfs(vector<int>& nums, vector<int> inter, int sum, int i) {
        if (sum == target) {
            res.push_back(inter);
            return;
        }
        if (i == nums.size() || sum > target) return;
        inter.push_back(nums[i]);
        dfs(nums, inter, sum+nums[i], i);
        inter.pop_back();
        dfs(nums, inter, sum, i+1);
    }
};
