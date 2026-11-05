    class Solution {
    vector<vector<bool>> visited;
    int rows, cols;

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    grid[nr][nc] == '1' && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    public:
        int numIslands(vector<vector<char>>& grid) {
            rows = grid.size()                      ;
            cols = grid[0].size();
            visited.assign(rows, vector<bool>(cols, false));
            int islands = 0;
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < cols; c++) {
                    if (grid[r][c] == '1' && !visited[r][c]) {
                        bfs(grid, r, c);
                        islands++;
                    }
                }
            }
            return islands;
        }
};