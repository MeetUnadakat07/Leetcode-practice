class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size()-1;
        while(st<=end) {
            int mid = st+(end-st)/2;
            if(nums[mid]==target) return mid;
            if(nums[st]<=nums[mid]) {       // L1
                if(nums[st]<=target && target<=nums[mid]) {     // Left
                    end = mid-1;
                }
                else {                                          // Right
                    st=mid+1;
                }
            }
            else {                          // L2
                if(nums[mid]<=target && target<=nums[end]) {    // Right
                    st=mid+1;
                }
                else {                                          // Left
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};
