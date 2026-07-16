class Solution {
public:
    int binarySearch(vector<int> &arr, int target) {
        int l = 0, r = arr.size() - 1;
        int ans = r;

        while(l <= r) {
            int mid = (l + r) / 2;
            if(arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > arr.back()) {
                arr.push_back(nums[i]);
            } else {
                int idx = binarySearch(arr, nums[i]);
                arr[idx] = nums[i];
            }
        }

        return arr.size();
    }
};
