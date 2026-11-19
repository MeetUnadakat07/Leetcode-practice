class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size() <= 3) return 0;

        int maxi[3] = {INT_MIN, INT_MIN, INT_MIN};
        int mini[3] = {INT_MAX, INT_MAX, INT_MAX};

        for(int ele : nums) {
            if(ele > maxi[0]) {
                maxi[2] = maxi[1];
                maxi[1] = maxi[0];
                maxi[0] = ele;
            } else if(ele > maxi[1]) {
                maxi[2] = maxi[1];
                maxi[1] = ele;
            } else if(ele > maxi[2]) {
                maxi[2] = ele;
            }

            if(ele < mini[0]) {
                mini[2] = mini[1];
                mini[1] = mini[0];
                mini[0] = ele;
            } else if(ele < mini[1]) {
                mini[2] = mini[1];
                mini[1] = ele;
            } else if(ele < mini[2]) {
                mini[2] = ele;
            }
        }

        return min({maxi[0] - mini[2], maxi[1] - mini[1], maxi[2] - mini[0]});
    }
};
