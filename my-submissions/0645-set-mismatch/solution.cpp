class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int repeated = -1, missing = -1;
        for(int i = 1; i <= nums.size(); i++) {
            if(freq[i] == 2) {
                repeated = i;
            }
            if(freq[i] == 0) {
                missing = i;
            }
        }
        return {repeated, missing};
    }
};
