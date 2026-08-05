class Solution {
private:
    int directions[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    void bt(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '.';
        for (auto [dr, dc] : directions) {
            int newr = row + dr;
            int newc = col + dc;
            if (newr >=0 && newr < grid.size()
            && newc >=0 && newc < grid[0].size()
            && grid[newr][newc] == '1') {
                bt(grid, newr, newc);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int row=0; row<grid.size(); row++) {
            for (int col=0; col<grid[0].size(); col++) {
                if (grid[row][col] == '1') {
                    num ++;
                    bt(grid, row, col);
                }
            }
        }
        return num;
    }
};
