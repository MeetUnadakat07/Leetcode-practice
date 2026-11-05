class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> front(cols, vector<int> (cols, 0));
        vector<vector<int>> curr(cols, vector<int> (cols, 0));

        for(int j1 = 0; j1 < cols; j1++) {
            for(int j2 = 0; j2 < cols; j2++) {
                if(j1 == j2) {
                    front[j1][j2] = grid[rows - 1][j1];
                } else {
                    front[j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
                }
            }
        }

        for(int i = rows - 2; i >= 0; i--) {
            for(int j1 = 0; j1 < cols; j1++) {
                for(int j2 = 0; j2 < cols; j2++) {
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;

                            if(j1 == j2) {
                                value = grid[i][j1];
                            } else {
                                value = grid[i][j1] + grid[i][j2];
                            }

                            if(j1 + dj1 >= 0 && j2 + dj2 >= 0 && j1 + dj1 < cols && j2 + dj2 < cols) {
                                value += front[j1 + dj1][j2 + dj2];
                            } else {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][cols - 1];
    }
};
