class TrieNode {
public:
    bool endOfWord;
    TrieNode* children[26];
};

class Solution {
private:
    int ROWS;
    int COLS;
    int directions[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    vector<string> res;
    TrieNode* root;
    void bt(string& inter, TrieNode* cur, const vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited) {
        if (!cur) return;
        if (cur->endOfWord) {
            res.push_back(inter);
            cur->endOfWord = false;
        }
        for (auto [dc, dr] : directions) {
            int newr = row + dr;
            int newc = col + dc;
            if (newr >=0 && newr < ROWS
            && newc >= 0 && newc < COLS && !visited[newr][newc]) {
                visited[newr][newc] = true;
                inter.push_back(board[newr][newc]);
                bt(inter, cur->children[board[newr][newc] - 'a'], board, newr, newc, visited);
                inter.pop_back();
                visited[newr][newc] = false;
            }
        }



    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        root = new TrieNode();
        TrieNode* cur = root;
        for (string word : words) {
            for (char c : word) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            cur->endOfWord = true;
            cur = root;
        }
        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++) {
                if (root->children[board[r][c] - 'a']) {
                    visited[r][c] = true;
                    string s(1, board[r][c]);
                    bt(s, root->children[board[r][c] - 'a'], board, r, c, visited);
                    visited[r][c] = false;

                }
            }
        }
        return res;


    }
};

// Reversing Grid Coordinates & Off-by-One Indexing: Mixing up (row, col) with (x, y) / board[j][i], leading to immediate out-of-bounds segfaults on non-square grids.

// Array Index vs. Character Value Mismanagement: Passing raw ASCII values (like 'a' / 97 or negative offsets from '.' - '0') directly into fixed-size array indices without proper bounds checks or subtracting 'a'/'0'.

// State & Backtracking Leakage: Forgetting to clear/undo state changes during traversal—such as omitting cur->endOfWord = false (causing duplicate results), missing explicit reset steps, or passing heavy objects by value instead of reference (&).