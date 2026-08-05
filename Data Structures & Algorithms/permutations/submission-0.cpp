class Solution {
private:
    vector<vector<int>> res;
    void bt(const vector<int>& nums, unordered_set<int> remaining, vector<int> inter) {
        if (remaining.empty()) {
            res.push_back(inter);
            return;
        }
        for (int n : remaining) {
            inter.push_back(n);
            unordered_set copy = remaining;
            copy.erase(n);
            bt(nums, copy, inter);
            inter.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        bt(nums, s, {});
        return res;
        
    }
};
