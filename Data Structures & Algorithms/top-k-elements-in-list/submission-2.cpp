class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> my_map;
        for (int num : nums) {
            my_map[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto kv : my_map) {
            // push the actual number into the buckets list
            buckets[kv.second].push_back(kv.first);
        }
        vector<int> res;
        int i=0;
        for (int j=nums.size(); j>0; j--) {
            for (int num : buckets[j]) {
                i++;
                res.push_back(num);

                if (i==k) {
                    return res;
                }
            }
        }
    };

};
