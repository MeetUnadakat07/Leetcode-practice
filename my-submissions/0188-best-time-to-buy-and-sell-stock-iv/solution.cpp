class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after (2, vector<int> (k + 1, 0));
        vector<vector<int>> curr (2, vector<int> (k + 1, 0));

        for(int idx = n - 1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++) {
                // for cap 0 answer will be 0 so we do not need to take that
                for(int cap = 1; cap <= k; cap++) {
                    if(buy == 1) {
                        int take = -prices[idx] + after[0][cap];
                        int notTake = after[1][cap]; 
                        curr[buy][cap] = max(take, notTake);
                    } else {
                        int sell = prices[idx] + after[1][cap - 1];
                        int notSell = after[0][cap];
                        curr[buy][cap] = max(sell, notSell);
                    }      
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};
