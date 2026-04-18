class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i])) {
                m[nums[i]]++;
            } else {
                m[nums[i]] = 1;
            }
        }
        
        for(pair<int, int> n : m) {
            if(n.second > (nums.size() / 3)) {
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};
