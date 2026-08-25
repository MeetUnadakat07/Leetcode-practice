class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = 1;
        for(int mul = k; ; mul += k) {
            if(!s.count(mul)) {
                return mul;
            }
        }
        return -1;
    }
};
