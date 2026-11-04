class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int MOD = 1e9 + 7;
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int> (fuel + 1, 0));

        for(int i = 0; i < n; i++) {
            dp[i][0] = (i == finish) ? 1 : 0;
        }

        for(int f = 0; f <= fuel; f++) {
            for(int curr = 0; curr < n; curr++) {
                int ans = (curr == finish) ? 1 : 0;

                for(int i = 0; i < n; i++) {
                    if(i == curr) {
                        continue;
                    }
                    int cost = abs(locations[curr] - locations[i]);

                    if(cost <= f) {
                        ans = (ans + dp[i][f - cost]) % MOD;
                    }
                }
                dp[curr][f] = ans;
            }
        }
        return dp[start][fuel];
    }
};
