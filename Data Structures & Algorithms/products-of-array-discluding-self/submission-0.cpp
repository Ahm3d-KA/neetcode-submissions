class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pre = {1};
        for (int i=1; i<nums.size(); i++) {
            pre.push_back(pre[i-1]*nums[i-1]);
        }


        vector<int>suf(nums.size());
        suf[nums.size()-1] = 1;

        for (int i=nums.size()-2; i>=0; i--) {
            suf[i] = suf[i+1]*nums[i+1];
        }


        vector<int>res(nums.size());
        for (int i=0; i<nums.size(); i++) {
            res[i] = pre[i] * suf[i];
        }
        return res;


    }
};
