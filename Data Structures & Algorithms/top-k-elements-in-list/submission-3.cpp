class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        vector<vector<int>>buckets(nums.size()+1);
        for (auto [k, v] : m) {
            buckets[v].push_back(k);
        }
        vector<int> res;
        for (int i = buckets.size()-1; i>=0; i--) {
            for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
        
    }
};
