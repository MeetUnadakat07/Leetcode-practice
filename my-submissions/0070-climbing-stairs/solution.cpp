class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        int prev = 1, curr = 1;
        int next;
        for(int i = 2; i <= n; i++) {
            next = prev + curr;
            prev = curr;
            curr = next;
        }
        return next;
    }
};
