class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int prev = 0;
        int curr = 0;

        for(int money : nums) {
            int next = max(curr, prev + money);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
