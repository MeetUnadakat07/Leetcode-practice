class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int p1 = 0, p2 = 0;
        for(int i = 0; i < m + n; i++) {
            int val1 = (p1 == m) ? INT_MAX : nums1[p1];
            int val2 = (p2 == n) ? INT_MAX : nums2[p2];
            if(val1 <= val2) {
                result.push_back(val1);
                p1++;
            } else {
                result.push_back(val2);
                p2++;
            }
        }
        for(int i = 0; i < m + n; i++) {
            nums1[i] = result[i];
        }
    }
};
