class Solution {
private:
    vector<vector<int>> res;
    void bt(vector<int>& nums, vector<int> inter, int i) {
        if (i == nums.size()) {
            res.push_back(inter);
            return;
        }
        bt(nums, inter, i+1);
        inter.push_back(nums[i]);
        bt(nums, inter, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> inter = {};
        bt(nums, inter, 0);
        return res;
        
    }
};
