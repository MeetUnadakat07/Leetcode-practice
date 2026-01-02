class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string ans = "";
        unsigned int n = num;
        while(n > 0) {
            int rem = n % 16;
            if(rem < 10) {
                ans = to_string(rem) + ans;
            } else {
                ans = (char) ('a' + rem - 10) + ans;
            }
            n /= 16;
        }
        return ans;
    }
};
