class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        for (char ch : s) {
            myMap[ch]++;
        }
        for (char ch : t) {
            myMap[ch]--;
        }
        for (auto pair : myMap) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;
        
    }
};
