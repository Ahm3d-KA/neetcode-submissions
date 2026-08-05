class Solution {
private:
    int directions[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    void bt(vector<vector<int>>& grid, int row, int col, int dist) {
        for (auto [dr, dc] : directions) {
            int newr = row + dr;
            int newc = col + dc;
            if (newr >=0 && newr < grid.size()
            && newc >= 0 && newc < grid[0].size() &&
            dist < grid[newr][newc]) {
                grid[newr][newc] = dist;
                bt(grid, newr, newc, dist+1);
            }

        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int row=0; row<grid.size(); row++) {
            for (int col=0; col<grid[0].size(); col++) {
                if (grid[row][col] == 0) {
                    bt(grid, row, col, 1);
                }
            }
        }

    }
};
