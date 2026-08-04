class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int tr = (nums.size()*(nums.size()+1)) / 2;
     int sum = reduce(nums.begin(), nums.end());
     return tr - sum; 
    }
};
