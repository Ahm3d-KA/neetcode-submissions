class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0; 
        int maxc=0;
        int maxs=0;
        unordered_map<char, int> count;
        while (r < s.length()) {
            count[s[r]]++; 
            for (auto kv : count) {
                maxc = max(maxc, kv.second); 
            }
            if (r - l  + 1 - maxc <= k) {
                maxs = max(maxs, r - l + 1);
                r++;
            }
            else {
                count[s[l]]--;
                l++; r++;
                maxc=0;
            }
        }
        return maxs;
    }
};
