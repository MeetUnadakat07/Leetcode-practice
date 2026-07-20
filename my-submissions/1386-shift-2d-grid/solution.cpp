class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < k; i++) {
            int prev = grid[n - 1][m - 1];

            for(int row = 0; row < n; row++) {
                for(int col = 0; col < m; col++) {
                    swap(prev, grid[row][col]);
                }
            }
        }
        return grid;
    }
};
