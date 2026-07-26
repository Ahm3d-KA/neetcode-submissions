class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int num : nums) {
            s.insert(num);
        }

        int maxc = 0;
        int count = 1;
        for (int num : s) {
            if (s.find(num+1)!=s.end()) {
                count ++;
            }
            else {
                maxc = max(maxc, count);
                count = 1;
            }
        }
        return maxc;
    }
};
