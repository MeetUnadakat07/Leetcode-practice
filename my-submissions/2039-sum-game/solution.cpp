class Solution {
public:
    bool sumGame(string num) {
        int qleft = 0, qright = 0, leftKnown = 0, rightKnown = 0;
        int n = num.size();
        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') {
                qleft++;
            } else {
                leftKnown += num[i] - '0';
            }
        }
        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?') {
                qright++;
            } else {
                rightKnown += num[i] - '0';
            }
        }

        // if there are odd number of unknowns then alice will always win as he will always get the first as well as last chance to play
        if(abs(qright - qleft) % 2) return true;

        // if there are k blank spaces (even) then bob will try to keep the difference at most of 9 so that he can cover the difference in his last turn
        return leftKnown != rightKnown + 9 * (qright - qleft) / 2;
    }
};
