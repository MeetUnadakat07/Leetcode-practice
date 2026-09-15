class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> num(101);
        for(int i = 0; i < nums.size(); i++) {
            num[nums[i]].push_back(i);
        }
        int count = 0;
        for(int i = 0; i < num.size(); i++) {
            if(num[i].size() == 3) {
                if(num[i][1] - num[i][0] == num[i][2] - num[i][1]) {
                    count++;
                }
            }
        }
        return count;
    }
};
