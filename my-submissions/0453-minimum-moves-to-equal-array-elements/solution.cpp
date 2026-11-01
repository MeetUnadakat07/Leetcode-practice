class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int minEle = *min_element(nums.begin(), nums.end());
        int sumOfEle = accumulate(nums.begin(), nums.end(), 0);
        
        return sumOfEle - n * minEle;
    }
};
