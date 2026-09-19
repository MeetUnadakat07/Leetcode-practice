class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        if(k < 0) return 0;

        int st = 0, end = 0, count = 0, ans = 0;

        while(end < nums.size()) {
            if(nums[end] % 2) {
                count++;
            }
            while(count > k) {
                if(nums[st] % 2) {
                    count--;
                }
                st++;
            }
            ans += (end - st + 1);
            end++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};
