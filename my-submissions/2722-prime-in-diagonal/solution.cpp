class Solution {
public:
    bool isPrime(int n) {
        if(n < 2) return false;
        for(int i = 2; i < n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        vector<int> diag;
        for(int i = 0; i < nums.size(); i++) {
            diag.push_back(nums[i][i]);
            diag.push_back(nums[i][nums.size() - 1- i]);
        }
        sort(diag.begin(), diag.end(), greater<int>());
        for(int ele : diag) {
            if(isPrime(ele)) return ele;
        }
        return 0;
    }
};
