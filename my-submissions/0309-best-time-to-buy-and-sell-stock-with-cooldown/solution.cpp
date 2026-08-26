class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        vector<int> curr(2, 0), next(2, 0);
        int nextBuy = 0;        // dp[idx + 2][1]

        for(int idx = n - 1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy == 1) {
                    int take = -prices[idx] + next[0];
                    int notTake = next[1];
                    curr[buy] = max(take, notTake);
                } else {
                    int sell = prices[idx] + nextBuy;
                    int notSell = next[0];
                    curr[buy] = max(sell, notSell);
                }
            }
            nextBuy = next[1];
            next = curr;
        }
        return curr[1];
    }
};
