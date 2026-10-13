class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        for(int i = 0; i < n; i++) {
            ans[i] = abs((long long) nums[i]);
        }

        int k = (n + 1) / 2;
        nth_element(ans.begin(), ans.begin() + k, ans.end(), greater<long long>());

        long long total = 0;
        for(int i = 0; i < k; i++) {
            total += ans[i] * ans[i];
        } 
        for(int i = k; i < n; i++) {
            total -= ans[i] * ans[i];
        }
        return total;
    }
};
