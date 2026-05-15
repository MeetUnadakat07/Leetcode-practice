class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size() - 1;
        while(st < end) {
            int mid = st + (end - st) / 2;
            if(nums[mid] > nums[end]) {     // Min is in the right half
                st = mid + 1;
            } else {                        // Min is in the left half (including the mid)
                end = mid;
            }
        }
        return nums[st];
    }
};
