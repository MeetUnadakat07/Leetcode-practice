class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        int st = newInterval[0];
        int end = newInterval[1];

        // Add the intervals before the start
        while(i < n && intervals[i][1] < st) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Check for which intervals to be merged
        while(i < n && intervals[i][0] <= end) {
            st = min(intervals[i][0], st);
            end = max(intervals[i][1], end);
            i++;
        }

        // add the merged interval
        ans.push_back({st, end});

        // Add the intervals after the end
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
