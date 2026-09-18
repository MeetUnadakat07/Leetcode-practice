class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sum, count
        unordered_map<int, int> m;
        m[0] = 1;   // at the start the sum is zerp and it has come 1 time
        int preSum = 0, count = 0;

        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            if(m.find(preSum - k) != m.end()) {
                count += m[preSum - k];
            }
            m[preSum]++;
        }
        return count;
    }
};
