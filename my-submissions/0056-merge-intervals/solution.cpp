class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            // overlapping
            if(intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                // non-overlapping
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
