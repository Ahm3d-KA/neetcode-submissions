class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> dups;
        for (int n : nums) {
            dups.insert(n);
        }
        return dups.size() != nums.size();
        
    }
};