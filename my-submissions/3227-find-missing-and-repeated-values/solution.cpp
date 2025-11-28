class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n*n;

        vector<int> freq(N+1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        int a, b;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] == 2) {
                a = i;
            }
            if(freq[i] == 0) {
                b = i;
            }
        }
        return {a, b};
    }
};
