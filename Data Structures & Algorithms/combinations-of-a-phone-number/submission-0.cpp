class Solution {
private:
    vector<vector<char>> m = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
    vector<string> res;
    void bt(string inter, string digits) {
        if (digits.empty()) {
            res.push_back(inter);
            return;
        }
        for (char c : m[digits[0]-'2']) {
            inter.push_back(c);
            bt(inter, digits.substr(1));
            inter.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        bt("", digits);
        return res;
    }
};
