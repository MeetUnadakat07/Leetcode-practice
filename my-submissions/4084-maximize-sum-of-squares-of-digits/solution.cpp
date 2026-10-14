class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num || sum < 0) return "";

        string result = "";

        for(int i = 0; i < num; i++) {
            int digit = min(9, sum);
            result += char('0' + digit);
            sum -= digit;
        }

        return result;
    }
};
