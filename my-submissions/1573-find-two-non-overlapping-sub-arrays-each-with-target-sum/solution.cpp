class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int st = 0, end = 0, currSum = 0;
        int n = arr.size();
        vector<int> minLenTillIdx(n, INT_MAX);
        int result = INT_MAX, bestMin = INT_MAX;

        while(end < n) {
            currSum += arr[end];
            while(currSum > target) {
                currSum -= arr[st];
                st++;
            }
            if(currSum == target) {
                int len = end - st + 1;

                if(st > 0 && minLenTillIdx[st - 1] != INT_MAX) {
                    result = min(result, len + minLenTillIdx[st - 1]);
                }
                bestMin = min(bestMin, len);
            }
            minLenTillIdx[end] = bestMin;
            end++;
        }
        return result == INT_MAX ? -1 : result;
    }
};
