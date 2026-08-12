class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int st = 0, end = 0;
        int ans = 0;
        unordered_map<int, int> m;

        while(end < nums.size()) {
            if(m[nums[end]] < k) {
                m[nums[end]]++;
                end++;
            } else {
                m[nums[st]]--;
                st++;
            }
            ans = max(ans, end - st);
        }
        return ans;
    }
};
