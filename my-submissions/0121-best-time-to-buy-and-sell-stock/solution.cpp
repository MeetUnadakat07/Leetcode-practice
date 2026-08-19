class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevMin = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++) {
            int currProfit = prices[i] - prevMin;
            maxProfit = max(maxProfit, currProfit);
            prevMin = min(prevMin, prices[i]);
        }
        return maxProfit;
    }
};
