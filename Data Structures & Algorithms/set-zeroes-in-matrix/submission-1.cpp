class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        vector<vector<bool>> m (ROWS, vector<bool>(COLS, false));
        bool topRow = false;
        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++)  {
                if (matrix[r][c] == 0) {
                    if (r == 0) {
                        topRow = true;
                    } 
                    else {
                        matrix[r][0] = 0;
                        matrix[0][c] = 0;
                    }
                    
                }
            }
        }
        for (int r=1; r<ROWS; r++) {
            if (matrix[r][0] == 0) {
                fill(matrix[r].begin(), matrix[r].end(), 0);
            }
        }
        for (int c=0; c<COLS; c++) {
            if (matrix[0][c] == 0) {
                for (int r=0; r<ROWS; r++) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (topRow) fill(matrix[0].begin(), matrix[0].end(), 0);
        
    }
};
