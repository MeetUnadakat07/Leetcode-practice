class Solution {
public:
    int largestInteger(int n, int s) {
        if(s > n * 9) return -1;
        if(s == 0) return 0;
        int ans = 0;

        while(n > 0) {
            if(s > 0 && s < 9) {
                ans = ans * 10 + s;
                s = 0;
            } else if(s >= 9) {
                ans = ans * 10 + 9;
                s -= 9;
            } else {
                ans *= 10;
            }
            n--;
        }
        return ans;
    }
};
