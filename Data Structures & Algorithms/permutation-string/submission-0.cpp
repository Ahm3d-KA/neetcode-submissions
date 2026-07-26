class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=0, r=s1.length()-1;
        unordered_map<char, int> count, cmp;
        for (char ch : s1) {
            count[ch]++;
        }
        while (r < s2.length()) {
            for (int i=l; i<=r; i++) {
                cmp[s2[i]]++;

            }
            if (cmp == count) {
                return true;
            }
            cmp.clear();
            l++; r++;

        }
        return false;
        
    }
};
