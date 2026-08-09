class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            string snum = to_string(n);
            int res = 0;
            for (char n : snum) {
                res += pow(n - '0', 2);
            }
            if (seen.contains(res)) return false;
            seen.insert(res);
            n = res;
        }
        return true;
        
    }
};
