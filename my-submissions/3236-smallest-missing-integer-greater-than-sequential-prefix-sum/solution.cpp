class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // find th elongest sequential prefix
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // check if it is present in the array
        unordered_set<int> s(nums.begin(), nums.end());
        
        // check for the smallest element >= sum that is not present
        while(s.count(sum)) {
            sum++;
        }

        return sum;
    }
};
