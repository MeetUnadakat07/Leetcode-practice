class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = 0;
        int r = 0, c = 0;

        while(i >= 0 && i < n && j >= 0 && j < m) {
            if(grid[i][j] == '0') {
                return {r, c};
            }

            r = i;
            c = j;

            if(grid[i][j] == 'U') {
                i--;
            } else if(grid[i][j] == 'D') {
                i++;
            } else if(grid[i][j] == 'L') {
                j--;
            } else {
                j++;
            }
            grid[r][c] = '0';
        }

        return {r, c};
    }
};
