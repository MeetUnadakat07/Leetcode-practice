class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int maxEle = *max_element(nums.begin(), nums.end());

        for(int ele : nums) {
            moves += (maxEle - ele);
        }
        return moves;
    }
};
