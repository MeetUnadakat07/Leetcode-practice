class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({ages[i], scores[i]});
        }
        sort(pairs.begin(), pairs.end());

        vector<int> dp(n);
        int ans = 0;

        for(int i = 0; i < n; i++) {
            dp[i] = pairs[i].second;
            for(int j = i - 1; j >= 0; j--) {
                if(pairs[i].second >= pairs[j].second) {
                    dp[i] = max(dp[i], dp[j] + pairs[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
