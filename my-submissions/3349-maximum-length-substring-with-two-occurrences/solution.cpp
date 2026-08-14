class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> m;
        int st = 0, end = 0;
        int maxi = 0;
        while (end < s.size()) {
            if (m[s[end]] == 2) {
                m[s[st]]--;
                st++;
            } else {
                m[s[end]]++;
                end++;
            }
            maxi = max(maxi, end - st);
        }
        return maxi;
    }
};
