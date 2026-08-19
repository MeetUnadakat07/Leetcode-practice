class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        curr[0] = true;
        for(int j = 1; j <= m; j++) {
            if(p[j - 1] == '*') {
                curr[j] = true;
            } else {
                break;
            }
        }
        prev = curr;

        for(int i = 1; i <= n; i++) {
            curr[0] = 0;
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if(p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
