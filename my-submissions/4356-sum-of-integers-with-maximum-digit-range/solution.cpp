class Solution {
public:
    int digitSum(int num) {
        int min = 10, max = 0;
        while(num > 0) {
            if(num % 10 <= min) {
                min = num % 10;
            }
            if(num % 10 >= max) {
                max = num % 10;
            }
            num /= 10;
        }
        return max - min;
    }
    
    int maxDigitRange(vector<int>& nums) {
        vector<int> m(nums.size(), 0);
        int maxSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = digitSum(nums[i]);
            m[i] = sum;
            maxSum = max(sum, maxSum);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(m[i] == maxSum) {
                ans += nums[i];
            }
        }
        return ans;
    }
};
