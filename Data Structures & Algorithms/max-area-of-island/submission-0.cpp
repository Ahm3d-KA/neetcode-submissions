class Solution {
private:
    int ROWS;
    int COLS;
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};
    int bfs(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] = 0;
        int area =1;
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            auto [row, col] = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nc >= 0 && nr >=0 && nc<COLS &&
                nr<ROWS && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                    area++;

                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int r=0; r<ROWS; r++) {
            for (int c=0; c<COLS; c++) {
                if (grid[r][c] == 1) {
                    maxArea = max(maxArea, bfs(grid, r, c));

                }
            }
        }
        return maxArea;
    }
};
