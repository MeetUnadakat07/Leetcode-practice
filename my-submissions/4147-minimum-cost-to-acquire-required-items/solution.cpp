class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost = 0;

        long long cost_1 = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long cost_2 = 1LL * max(need1, need2) * costBoth;
        long long cost_3 = 1LL * min(need1, need2) * costBoth;
        if(need1 < need2) {
            cost_3 += 1LL * (need2 - need1) * cost2;
        } else {
            cost_3 += 1LL * (need1 - need2) * cost1;
        }
        return min({cost_1, cost_2, cost_3});
    }
};
