class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int totalCost = 0;
        int i = n - 1;
        while(i > 1) {
            totalCost += cost[i];
            totalCost += cost[i - 1];
            i -= 3;
        }
        while(i >= 0) {
            totalCost += cost[i];
            i--;
        }
        return totalCost;
    }
};
