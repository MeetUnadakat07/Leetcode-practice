class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> freq;
        for(int ele : nums) {
            freq[ele]++;
        }

        if(k == 1) {
            int ans = -1;
            for(int ele : nums) {
                if(freq[ele] == 1) {
                    ans = max(ans, ele);
                }
            }
            return ans;
        }

        int ans = -1;
        if(freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        
        if(freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
