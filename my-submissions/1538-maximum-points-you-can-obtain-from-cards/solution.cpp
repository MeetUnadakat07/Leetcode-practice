class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0, rSum = 0, maxPts = 0;
        int n = cardPoints.size();
        for(int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }
        maxPts = lSum;
        int rIdx = n - 1;
        for(int i = k - 1; i >= 0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[rIdx];
            rIdx--;
            maxPts = max(maxPts, lSum + rSum);
        }
        return maxPts;
    }
};
