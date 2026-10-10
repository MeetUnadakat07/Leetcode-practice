class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans{-1, -1};
        int maxProd = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            
            if(m.find(rem) != m.end()) {
                int j = m[rem];
                
                if(nums[i] == nums[j]) continue;
                
                int prod = nums[i] * nums[j];

                if(prod > maxProd) {
                    maxProd = prod;
                    if(nums[i] > nums[j]) {
                        ans[0] = i;
                        ans[1] = j;
                    } else {
                        ans[0] = j;
                        ans[1] = i;
                    }
                }
            }
            m[nums[i]] = i;
        }
        
        return ans;
    }
};
