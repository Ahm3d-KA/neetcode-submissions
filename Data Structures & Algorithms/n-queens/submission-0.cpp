class Solution {
private:
    vector<vector<string>> res;
    void bt(int r, int n, vector<bool> cols, vector<bool> pos_diag, vector<bool> neg_diag, vector<string> inter) {
        if (r == n) {
            res.push_back(inter);
            return;
        }
        for (int c=0; c<n; c++) {
            if (!cols[c] && !pos_diag[r+c] && !neg_diag[r-c+n]) {
                cols[c] = true;
                pos_diag[r+c] = true;
                neg_diag[r-c+n] = true;
                inter[r][c] = 'Q';
                bt(r+1, n, cols, pos_diag, neg_diag, inter);
                cols[c] = false;
                pos_diag[r+c] = false;
                neg_diag[r-c+n] = false;
                inter[r][c] = '.';


            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> inter(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> pos_diag(n*3, false);
        vector<bool> neg_diag(n*3, false);
        bt(0, n, cols, pos_diag, neg_diag, inter);
        return res;
        
    }
};
