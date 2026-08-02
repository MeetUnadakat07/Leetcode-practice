class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int maxLen = 0;
        int r = 0, l = 0;

        while(r < s.size()) {
            if(hash[s[r]] != -1) {
                if(hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
