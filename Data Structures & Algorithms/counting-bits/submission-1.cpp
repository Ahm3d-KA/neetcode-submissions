class Solution {
public:
    vector<int> countBits(int n) {
        if (n==0) return {0};
        vector<int> res = {0, 1};
        int offset = 2;
        for (int i=2; i<=n; i++) {
            if (log2(i) == floor(log2(i))) {
                offset = i;
            }
            res.push_back(1 + res[i - offset]);

        }
        return res;
    }
};
