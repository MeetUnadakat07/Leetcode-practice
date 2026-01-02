class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string ans = "";
        int ogNum = num;
        if(num < 0) {
            num = num * -1;
        }
        while(num > 0) {
            int rem = num % 7;
            ans = to_string(rem) + ans;
            num /= 7;
        }
        if(ogNum < 0) {
            ans = "-" + ans;
        }
        return ans;
    }
};
