class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets (nums.size()+1, vector<int>());
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }
        for (auto [num, freq] : m) {
            buckets[freq].push_back(num);
        }
        int c = buckets.size()-1;
        vector<int> res;
        for (int i=0; i<k; i++) {
            while(buckets[c].empty()) {
                c--;
            }
            res.push_back(buckets[c].back()); buckets[c].pop_back();

        }
        return res;
    }
};
