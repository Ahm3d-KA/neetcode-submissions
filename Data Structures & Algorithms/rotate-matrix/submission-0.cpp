class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ROWS = matrix.size();
        int c=0;
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<c; j++) {
                // if (i == j) continue;
                // int temp = matrix[i][j];
                // matrix[i][j] = matrix[j][i];
                // matrix[j][i] = temp;
                swap(matrix[i][j], matrix[j][i]);
            }
            c++;
        }
        for (vector<int>& r : matrix) {
            reverse(r.begin(), r.end());
        }   
    }
};
