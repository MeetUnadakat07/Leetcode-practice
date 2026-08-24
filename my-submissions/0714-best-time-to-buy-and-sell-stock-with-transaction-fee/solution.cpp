class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        vector<int> next(2), curr(2);

        for(int idx = prices.size() - 1; idx >= 0; idx--) {
            for(int buy = 1; buy >= 0; buy--) {
                if(buy == 1) {
                    int take = -prices[idx] +  next[0];
                    int notTake = next[1];
                    curr[buy] = max(take, notTake);
                } else {
                    int sell = prices[idx] - fee + next[1];
                    int notSell = next[0];
                    curr[buy] = max(sell, notSell);
                }
            }
            next = curr;
        }
        return next[1];
    }
};
