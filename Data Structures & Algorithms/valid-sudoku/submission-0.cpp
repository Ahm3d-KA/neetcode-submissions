class Solution {
private:
    bool rows(const vector<vector<char>>& b) {
        for (vector<char> r : b) {
            vector<int> test (9, 0);
            for (char c : r) {
                if (c == '.') continue;
                test[c-'1']++;
                if (test[c - '1'] > 1) { 
                    return false;
                }
                
            }

        }
        return true;
    }
    bool cols(const vector<vector<char>>& b) {
        for (int i=0; i<9; i++) {
            vector<int> test (9, 0);
            for (int j=0; j<9; j++) {
                if (b[j][i] == '.') continue;  
                test[(b[j][i])-'1']++; 
                if (test[(b[j][i])-'1'] > 1) {
                    return false;
                }
                

            }
        }
        return true;
    }

    bool boxes(const vector<vector<char>>& b) {
        for (int bi=0; bi<9; bi++) {
            vector<int> test (9, 0);
            int row = (bi / 3)  * 3;
            int col = (bi % 3) * 3;
            for (int r=0; r<3; r++) {
                for (int c=0; c<3; c++) {
                    if (b[row+r][col+c] == '.') continue;
                    test[(b[row+r][col+c])-'1']++;
                    if (test[(b[row+r][col+c])-'1'] > 1) {
                        return false;
                    }
                    
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return rows(board) && cols(board) && boxes(board);
        
    }
};
