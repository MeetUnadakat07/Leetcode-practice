class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        int count = 0;
        for(auto p : m) {
            vector<int> ind = p.second;
            if(ind.size() >= 3) {
                int diff = ind[1] - ind[0];
                bool same = true;
                for(int j = 1; j < ind.size(); j++) {
                    if(ind[j] - ind[j - 1] != diff) {
                        same = false;
                        break;
                    }
                }
                if(same) count++;
            }
        }
        return count;
    }
};
