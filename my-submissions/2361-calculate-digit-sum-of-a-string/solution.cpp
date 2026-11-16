class Solution {
public:
    string sum(string &s, int k) {
        string ans = "";
        int i = 0;
        while(i < s.size()) {
            int sum = 0;
            for(int j = i; j < min(i + k, (int)s.size()); j++) {
                sum += s[j] - '0';
            }
            i += k;
            ans += to_string(sum);
        }
        return ans;
    }

    string digitSum(string s, int k) {
        while(s.size() > k) {
            s = sum(s, k);
        }
        return s;
    }
};
