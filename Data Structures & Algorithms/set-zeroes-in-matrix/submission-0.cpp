class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<bool>> m (ROWS, vector<bool>(COLS, false));
        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++)  {
                if (matrix[r][c] == 0) {
                    fill(m[r].begin(), m[r].end(), true);
                    for (int i=0; i<ROWS; i++) {
                        m[i][c] = true;
                    }
                }
            }
        }
        for (int r=0; r<ROWS; r++)  {
            for (int c=0; c<COLS; c++) {
                if (m[r][c]) {
                    matrix[r][c] = 0;
                }
            }
        }
        
    }
};
