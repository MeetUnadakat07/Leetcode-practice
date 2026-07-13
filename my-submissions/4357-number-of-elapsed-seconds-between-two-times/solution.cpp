class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        vector<int> stTime(3);
        vector<int> finishTime(3);
        stTime[0] = stoi(startTime.substr(0, 2));
        stTime[1] = stoi(startTime.substr(3, 2));
        stTime[2] = stoi(startTime.substr(6, 2));

        finishTime[0] = stoi(endTime.substr(0, 2));
        finishTime[1] = stoi(endTime.substr(3, 2));
        finishTime[2] = stoi(endTime.substr(6, 2));

        int hrDiff = finishTime[0] - stTime[0];
        int minDiff = finishTime[1] - stTime[1];
        int secDiff = finishTime[2] - stTime[2];

        int ans = 3600 * hrDiff + 60 * minDiff + secDiff;
        return ans;
    }
};
