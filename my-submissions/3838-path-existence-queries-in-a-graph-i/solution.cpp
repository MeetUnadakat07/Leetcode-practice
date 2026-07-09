class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> path;
        int currGroup = 0;
        vector<int> group(n, 0);

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] > maxDiff) {
                currGroup++;
            }
            group[i] = currGroup;
        }

        for(auto p : queries) {
           int u = p[0], v = p[1];
           path.push_back(group[u] == group[v]);
        }
        return path;
    }
};
