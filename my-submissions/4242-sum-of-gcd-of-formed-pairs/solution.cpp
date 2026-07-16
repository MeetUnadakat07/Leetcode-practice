class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        int maximum = 0;

        vector<int> prefix(n);

        for(int i = 0; i < n; i++) {
            maximum = max(maximum, nums[i]);
            prefix[i] = gcd(nums[i], maximum);
        }

        sort(prefix.begin(), prefix.end());

        int st = 0, end = n - 1;
        while(st < end) {
            sum += gcd(prefix[st], prefix[end]);
            st++;
            end--;
        }
        return sum;
    }
};
