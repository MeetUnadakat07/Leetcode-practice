class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size());
        long long prod = 1;
        int zeroCount = 0;
        for(int ele : nums) {
            if(ele != 0) {
                prod *= ele;
            } else {
                zeroCount++;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(zeroCount > 1) {
                products[i] = 0;
            } else if(zeroCount == 1) {
                products[i] = (nums[i] == 0) ? prod : 0;
            } else {
                products[i] = prod / nums[i];
            }
        }
        return products;
    }
};
