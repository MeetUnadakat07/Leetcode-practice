class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freeCount(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        int cheapestPrice = INT_MAX;
        for(int i = 0; i < n; i++) {
            cheapestPrice = min(cheapestPrice, items[i][1]);
        }

        vector<vector<int>> dp(n + 1, vector<int> (budget + 1, 0));

        for(int i = 0; i <= budget; i++) {
            dp[0][i] = i / cheapestPrice;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= budget; j++) {
                int price = items[i - 1][1];
                int take = 0;

                if(price <= j) {
                    take = 1 + freeCount[i - 1] + dp[i - 1][j - price];
                }
                int skip = dp[i - 1][j];

                dp[i][j] = max(take, skip);
            }
        }
        return dp[n][budget];
    }
};
