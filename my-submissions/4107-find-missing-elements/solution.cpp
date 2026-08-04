class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        for(int ele : nums) {
            maxi = max(maxi, ele);
            mini = min(mini, ele);
        }
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = mini; i <= maxi; i++) {
            if(s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
