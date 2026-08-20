class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        // vector<vector<int>> dp(n, vector<int> (2, 0));
        vector<int> prev(2, 0), curr(2, 0);

        // hold -> am i holding or not. hold == 0 (not holding) hold == 1 (holding)

        prev[0] = 0;
        prev[1] = -prices[0];

        for(int idx = 1; idx < n; idx++) {
            for(int hold = 0; hold < 2; hold++) {
                if(hold) {
                    int buy = -prices[idx] + prev[0];
                    int notBuy = prev[1];
                    curr[hold] = max(buy, notBuy);
                } else {
                    int sell = prices[idx] + prev[1];
                    int notSell = prev[0];
                    curr[hold] = max(sell, notSell);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};
