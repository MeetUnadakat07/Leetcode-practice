class Solution {
public:
    int rob1(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int prev = nums[0];
        int curr = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            int next = max(curr, prev + nums[i]);
            prev = curr;
            curr = next;
        }
        return curr;
    }

    int rob(vector<int> &nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> temp1, temp2;
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size() - 1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1), rob1(temp2));
    }
};
