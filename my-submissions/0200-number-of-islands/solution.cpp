class Solution {
public:
    void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<bool>> &vis, int n, int m) {
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == '0' || vis[r][c]) {
            return;
        }

        vis[r][c] = true;

        dfs(r - 1, c, grid, vis, n, m);
        dfs(r + 1, c, grid, vis, n, m);
        dfs(r, c - 1, grid, vis, n, m);
        dfs(r, c + 1, grid, vis, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid, vis, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }
};
