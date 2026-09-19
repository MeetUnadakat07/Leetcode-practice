class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        if(k < 0) return 0;
        int st = 0, end = 0, ans = 0;

        unordered_map<int, int> freq;
        while(end < nums.size()) {
            freq[nums[end]]++;

            while(freq.size() > k) {
                freq[nums[st]]--;
                if(freq[nums[st]] == 0) {
                    freq.erase(nums[st]);
                }
                st++;
            }
            ans += (end - st + 1);
            end++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};
