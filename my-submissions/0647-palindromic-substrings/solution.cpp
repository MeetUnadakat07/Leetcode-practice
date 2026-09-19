class Solution {
public:
    int expandAroundCenter(int st, int end, string &s) {
        int count = 0;
        while(st >= 0 && end <= s.size() && s[st] == s[end]) {
            count++;
            st--;
            end++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            count += expandAroundCenter(i, i, s);
            count += expandAroundCenter(i, i + 1, s);
        }
        return count;
    }
};
