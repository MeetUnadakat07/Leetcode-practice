class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0, currSum = 0, maxLen = -1;
        int sum = 0;

        for(int ele : nums) {
            sum += ele;
        }
        if(sum < x) return -1;

        int target = sum - x;

        for(int right = 0; right < n; right++) {
            currSum += nums[right];

            while(left <= right && currSum > target) {
                currSum -= nums[left];
                left++;
            }

            if(currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};
