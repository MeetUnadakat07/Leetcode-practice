class Solution {
public:
    int maxLength(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ml = 1;

        for(int x : nums) {
            ml = lcm(ml, x);
        }

        long long limit = 1LL * ml * mx;

        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            long long prod = 1;
            long long l = 1;
            long long g = 0;

            for(int j = i; j < nums.size(); j++) {
                prod *= nums[j];
                l = lcm(l, (long long) nums[j]);
                g = gcd(g, (long long) nums[j]);

                if(prod == g * l) {
                    maxLen = max(maxLen, j - i + 1);
                }

                if(prod > limit) {
                    break;
                }
            }
        }
        return maxLen;
    }
};
