class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX, minIdx = -1;
        int maxi = INT_MIN, maxIdx = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIdx = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                minIdx = i;
            }
        }

        int ans = 0;
        ans += min(minIdx + 1, n - minIdx);
        ans += min(maxIdx + 1, n - maxIdx);
        ans = min({max(minIdx, maxIdx) + 1, // both from left
                n - min(minIdx, maxIdx),    // both from right
                minIdx + 1 + n - maxIdx,    // min left, max right
                maxIdx + 1 + n - minIdx }); // min right, max left
            return ans;
    }
};
