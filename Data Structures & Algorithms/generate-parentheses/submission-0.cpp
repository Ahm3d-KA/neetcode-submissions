class Solution {
private:
    vector<string> res;
    void bt(int n, int open, int close, string inter) {
        if (inter.length() == 2*n) {
            if (open == close) res.push_back(inter);
            return;
        }
        if (open >= close) {
            inter.push_back('(');
            bt(n, open+1, close, inter);
            if (open > close) {
                inter.pop_back();
                inter.push_back(')');
                bt(n, open, close+1, inter);                
            }

        }

    }
public:
    vector<string> generateParenthesis(int n) {
        bt(n, 0, 0, "");
        return res;
    }
};
