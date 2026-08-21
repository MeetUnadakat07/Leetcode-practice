class Solution {
public:
    int rec(vector<int> &prices, int idx, int buy, int k, vector<vector<vector<int>>> &dp) {
        if(idx == prices.size() || k == 0) return 0;

        if(dp[idx][buy][k] != -1) {
            return dp[idx][buy][k];
        }

        int ans = 0;

        // you can buy
        if(buy == 1) {
            int buy = -prices[idx] + rec(prices, idx + 1, 0, k, dp);
            int notBuy = rec(prices, idx + 1, 1, k, dp); 
            ans += max(buy, notBuy);
        } else {
            int sell = prices[idx] + rec(prices, idx + 1, 1, k - 1, dp);
            int notSell = rec(prices, idx + 1, 0, k, dp);
            ans += max(sell, notSell);
        }
        return dp[idx][buy][k] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int k = 2, n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        return rec(prices, 0, 1, k, dp);
    }
};
