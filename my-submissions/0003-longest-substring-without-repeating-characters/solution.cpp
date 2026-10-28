class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, l = 0, r = 0;
        int n = s.size();
        vector<int> freq(128, 0);
        
        for(int r = 0; r < s.size(); r++) {
            while(freq[s[r]] > 0) {
                freq[s[l]]--;
                l++;
            }

            freq[s[r]]++;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
