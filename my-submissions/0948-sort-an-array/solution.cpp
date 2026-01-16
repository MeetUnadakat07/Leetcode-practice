class Solution {
public:
    void merge(vector<int>& nums, int st, int mid, int end, vector<int>& temp) {
        int i = st, j = mid + 1, k = st;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= end) temp[k++] = nums[j++];

        for (int idx = st; idx <= end; idx++) {
            nums[idx] = temp[idx];
        }
    }

    void mergeSort(vector<int>& nums, int st, int end, vector<int>& temp) {
        if (st >= end) return;

        int mid = st + (end - st) / 2;
        mergeSort(nums, st, mid, temp);
        mergeSort(nums, mid + 1, end, temp);
        merge(nums, st, mid, end, temp);
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) return nums;   

        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};

