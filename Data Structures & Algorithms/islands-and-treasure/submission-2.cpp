class Solution {
private:
    int directions[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int r=0; r<grid.size(); r++) {
            for (int c=0; c<grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }
        int dist =0;
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (auto [dr, dc] : directions) {
                int newr = row + dr;
                int newc = col + dc;
                if (newr >=0 && newr <grid.size()
                && newc >=0 && newc < grid[0].size() &&
                grid[row][col] < grid[newr][newc]) {
                    grid[newr][newc] = grid[row][col] +1;
                    q.push({newr, newc});
                }

            }
        }
        
    }
};
