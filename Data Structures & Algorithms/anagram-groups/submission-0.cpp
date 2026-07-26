class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string key(26, '0');
        unordered_map<string, vector<string>> my_map;
        int index;
        for (auto str : strs) {
            for (char ch : str) {
                index = ch - 'a';
                key[index]++;
            }
            my_map[key].push_back(str);
            fill(key.begin(), key.end(), '0');
        }
        vector<vector<string>> res;
        for (auto item : my_map) {
            res.push_back(item.second);
        }
        return res;
};
};
