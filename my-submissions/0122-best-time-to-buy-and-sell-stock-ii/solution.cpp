class Solution {
public:
    int rec(int i, int buyStatus, vector<int> &prices, vector<vector<int>> &dp, int n) {
        if(i == n) return 0;

        if(dp[i][buyStatus] != -1) {
            return dp[i][buyStatus];
        }

        int ans = 0;
        if(buyStatus == 0) {
            int buy = -prices[i] + rec(i + 1, 1, prices, dp, n);
            int notBuy = rec(i + 1, 0, prices, dp, n);
            ans = max(buy, notBuy);
        } else {
            int sell = prices[i] + rec(i + 1, 0, prices, dp, n);
            int notSell = rec(i + 1, 1, prices, dp, n);
            ans = max(sell, notSell);
        }

        dp[i][buyStatus] = ans;
        return ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int> (2, -1));
        return rec(0, 0, prices, dp, n);
    }
};
