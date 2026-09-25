class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int endTime = -1e9, count = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        for(int i = 0; i < n; i++) {
            if(intervals[i][0] < endTime) {
                count++;
            } else {
                endTime = intervals[i][1];
            }
        }
        return count;
    }
};
