class Solution {
public:
    bool isMatch(string t, string p) {
        int n = t.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        dp[0][0] = true;

        for(int j = 1; j <= m; j++) {   // initialize 0th row -> tect = ""
            if(p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // 0th col -> pattern = "" (all will be false only)

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(t[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        // for(int i = 0; i <= n; i++) {
        //     for(int j = 0; j <= m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[n][m];
    }
};
