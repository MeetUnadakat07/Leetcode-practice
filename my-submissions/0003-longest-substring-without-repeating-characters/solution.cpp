class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(128, 0);
        int st = 0, end = 0;
        int maxLen = 0;
        
        while(st <= end && end < s.size()) {
            if(hash[s[end]] != 0) {
                hash[s[st]]--;
                st++;
            } else {
                hash[s[end]]++;
                end++;
            }
            maxLen = max(maxLen, end - st);
        }
        return maxLen;
    }
};
