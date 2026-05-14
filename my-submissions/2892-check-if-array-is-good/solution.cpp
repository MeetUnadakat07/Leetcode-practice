class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> freq(n + 1, 0);
        for(int ele : nums) {
            if(ele < 1 || ele > n) return false;
            freq[ele]++;
        }

        if(freq[n] != 2) return false;

        for(int i = 1; i < n; i++) {
            if(freq[i] != 1) return false;
        }

        return freq[n] == 2;
    }
};
