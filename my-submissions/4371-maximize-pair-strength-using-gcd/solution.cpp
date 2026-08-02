class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        long long ans = 0;
        int n = nums.size();

        for(int i = 0; i < n - 1; i++) {
            if(1LL * nums[i] * nums[i + 1] <= ans) {
                break;
            }

            for(int j = i + 1; j < n; j++) {
                long long g = gcd(nums[i], nums[j]);
                long long curr = (1LL * nums[i] * nums[j]) / (g * g);
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
