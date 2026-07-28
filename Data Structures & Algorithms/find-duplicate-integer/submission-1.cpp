class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        while (true) {
            f = nums[nums[f]];
            s = nums[s];
            if (s == f) { 
                break;
            }

        }
        int s2 =0;
        while (s != s2) {
            s2 = nums[s2];
            s = nums[s];
        }
        return s;
        
        
    }
};
