class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        int maxlen = 0;
        unordered_set<char> st;
        while (r < s.length()) {
            while (st.contains(s[r])) {
                st.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            st.insert(s[r]);
            r++;
        }
        return maxlen;
    }
};
