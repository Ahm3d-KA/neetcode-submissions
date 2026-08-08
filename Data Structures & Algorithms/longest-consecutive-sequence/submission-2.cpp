class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort (nums.begin(), nums.end());
        int maxl = 1;
        int i=0, streak=0;
        int curr = nums[0];
        while (i < nums.size()) {
            if (nums[i] != curr) {
                
                streak =0;
                curr = nums[i];
            }
            while (i < nums.size() && nums[i] == curr) i++;
            curr++;
            streak++;
            maxl = max(maxl, streak);

        }
        return maxl;

        
    }
};
