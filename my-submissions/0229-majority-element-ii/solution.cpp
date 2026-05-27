class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }
        for(pair<int, int> p : m) {
            if(p.second > n / 3) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
