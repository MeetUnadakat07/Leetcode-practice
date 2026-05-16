class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;
        while(st < end) {
            int mid = st + (end - st) / 2;
            if(nums[st] < nums[end]) {
                return nums[st];
            } else if(nums[mid] < nums[end]) {
                end = mid;
            } else if(nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end--;
            }
        }
        return nums[st];
    }
};
