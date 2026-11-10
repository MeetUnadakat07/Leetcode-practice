class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int next1 = 0, next2 = 0, next3 = 0;

        for(int i = n - 1; i >= 0; i--) {
            int one = next1 + costs[i] + 1;

            int two = 1e9, three = 1e9;

            if(i + 2 <= n) {
                two = next2 + costs[i + 1] + 4;
            }
            if(i + 3 <= n) {
                three = next3 + costs[i + 2] + 9;
            }
            int curr = min({one, two, three});

            next3 = next2;
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
};
