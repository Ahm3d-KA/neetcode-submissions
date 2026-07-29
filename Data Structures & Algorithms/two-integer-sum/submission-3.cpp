class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, pair<int, int>> m;
        for (int i=0; i<nums.size(); i++) {
            if (m[target-nums[i]].second > 0) {
                return {m[target-nums[i]].first, i};
            }
            m[nums[i]] = {i, 1};
        }
    }
};
