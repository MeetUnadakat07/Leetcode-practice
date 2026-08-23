class Solution {
public:
    bool isPal(string s) {
        int st = 0, end = s.size() - 1;
        while(st < end) {
            if(s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    bool isPalindromic(string s) {
        string ans = "";
        for(char ch : s) {
            int dec = ch;
            ans += bitset<8>(dec).to_string();
        }
        return isPal(ans);
    }
};
