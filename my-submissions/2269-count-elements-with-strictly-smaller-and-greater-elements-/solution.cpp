class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int ele : nums) {
            if(nums.front() < ele && ele < nums.back()) {
                count++;
            }
        }
        return count;
    }
};
