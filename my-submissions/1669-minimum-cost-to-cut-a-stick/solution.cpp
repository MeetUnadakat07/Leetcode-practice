class Solution {
public:
    int cut(vector<int> &cuts, vector<vector<int>> &dp, int i, int j) {
        if(i > j) return 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = INT_MAX;
        for(int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1];
            int r = cost + cut(cuts, dp, i, k - 1) + cut(cuts, dp, k + 1, j);
            res = min(res, r);
        }
        dp[i][j] = res;
        return res;
    }

    int minCost(int n, vector<int>& c) {
        vector<int> cuts;
        cuts.push_back(0);
        for(int ele : c) {
            cuts.push_back(ele);
        }
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int s = cuts.size();

        vector<vector<int>> dp(s, vector<int> (s, -1));

        return cut(cuts, dp, 1, s - 2);
    }
};
