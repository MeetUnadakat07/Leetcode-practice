class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nextGreater(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            int j = 0;
            while(j < nums2.size() && nums2[j] != nums1[i]) {
                j++;
            }
            while(j < nums2.size()) {
                if(nums2[j] > nums1[i]) {
                    nextGreater[i] = nums2[j];
                    break;
                }
                j++;
            }
        }
        return nextGreater;
    }
};
