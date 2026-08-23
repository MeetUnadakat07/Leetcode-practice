class Solution {
public:
    int rec(vector<int> &prices, int fee, int idx, int buy, vector<vector<int>> &dp) {
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy == 1) {
            int take = -prices[idx] + rec(prices, fee, idx + 1, 0, dp);
            int notTake = rec(prices, fee, idx + 1, 1, dp);
            return dp[idx][buy] = max(take, notTake);
        } else {
            int sell = prices[idx] - fee + rec(prices, fee, idx + 1, 1, dp);
            int notSell = rec(prices, fee, idx + 1, 0, dp);
            return dp[idx][buy] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return rec(prices, fee, 0, 1, dp);
    }
};
