class Solution {
public:
    int findMin(vector<int> &nums) {
        int l{}, r = nums.size()-1;
        int m{};
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[r] < nums[m]) {
                l = m + 1;
            }
            else if (nums[l] > nums[m]) {
                r = m;
            }
            else if (m-1 >=0 && nums[m-1] < nums[m]) {
                r = m;
            }
            else {
                return nums[m];
            }
        }
        return nums[m];
    }
};
