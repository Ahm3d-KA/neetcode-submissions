class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            if (m[n] > 0) {
                return n;
            }
            m[n]++;
        }
        
    }
};
