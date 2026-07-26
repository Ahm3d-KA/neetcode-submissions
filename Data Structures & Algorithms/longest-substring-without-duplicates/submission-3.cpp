class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxs = 0, l=0, r=0;
        string ss;
        while (r<s.length()) {
            // if next char is found in current substr {
            ss = s.substr(l, r-l);
            if (ss.contains(s[r])) { 
                l++;
            }
            else {
                maxs = max(maxs, r - l+1);
                r++;
            }
        }
        return maxs;
        
    }
};
