class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for (int num : nums) {
            int size = res.size();
            for (int i=0; i<size; i++) {
                vector<int> newsub = res[i];
                newsub.push_back(num);
                res.push_back(newsub);
            }
        }
        return res;
        
        
    }
};
