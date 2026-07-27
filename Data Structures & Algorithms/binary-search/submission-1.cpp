class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p;
        int l=0, r=nums.size()-1;
        while (l <= r) {
            p = (r - l) / 2 + l;
             if (target == nums[p]) {
            return p;
            }
            else if (target > nums[p]) {
                l = p + 1;
            }
            else {
                r = p - 1;
           
         }
        }
        return -1;
       
        
    }
};
