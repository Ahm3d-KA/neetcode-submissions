class Solution {
private:
    vector<int> res;
    void across(const vector<vector<int>>& matrix, int row, int cstart, int cend) {
        for (int i=cstart; i<=cend; i++) {
            res.push_back(matrix[row][i]);
        }
    }
    void along(const vector<vector<int>>& matrix, int col, int rstart, int rend) {
        for (int j=rstart; j<=rend; j++) {
            res.push_back(matrix[j][col]);
        }
    }
    void acrossR(const vector<vector<int>>& matrix, int row, int cstart, int cend) {
        for (int i=cstart; i>=cend; i--) {
            res.push_back(matrix[row][i]);
        }
    }
    void alongR(const vector<vector<int>>& matrix, int col, int rstart, int rend) {
        for (int j=rstart; j>=rend; j--) {
            res.push_back(matrix[j][col]);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int cstart {};
        int cend { COLS - 1 };
        int rstart {};
        int rend { ROWS - 1 };


        while (true) {
            if (cstart > cend) return res;
            across(matrix, rstart, cstart, cend);

            rstart++;
            if (rstart > rend) return res;
            along(matrix, cend, rstart, rend);

            cend--;
            if (cend < cstart) return res;
            acrossR(matrix, rend, cend, cstart);

            rend--;
            if (rend < rstart) return res;
            alongR(matrix, cstart, rend, rstart);

            cstart ++;
        }
        
    }
};
