class Solution {
public:
    int dfs(int r, int c, int rows, int cols, vector<vector<int>> &grid) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return 0;
        }

        // if we found water or already visited
        if (grid[r][c] == 1 || grid[r][c] == 2) {
            return 1;
        }

        // MArk the cell as visited
        grid[r][c] = 2;

        int left = dfs(r, c - 1, rows, cols, grid);
        int right = dfs(r, c + 1, rows, cols, grid);
        int up = dfs(r - 1, c, rows, cols, grid);
        int down = dfs(r + 1, c, rows, cols, grid);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    count += dfs(i, j, rows, cols, grid);
                }
            }
        }
        return count;
    }
};
