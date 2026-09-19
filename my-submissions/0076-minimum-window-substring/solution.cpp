class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = 1e9, stIdx = -1;
        unordered_map<char, int> freq;
        for(char ch : t) {
            freq[ch]++;
        }
        int req = freq.size();
        int st = 0, end = 0, count = 0;

        while(end < s.size()) {
            freq[s[end]]--;
            if(freq[s[end]] == 0) {
                count++;
            }

            while(count == req) {
                if(end - st + 1 < minLen) {
                    minLen = end - st + 1;
                    stIdx = st;
                }
                freq[s[st]]++;
                if(freq[s[st]] > 0) {
                    count--;
                }
                st++;
            }
            end++;
        }

        if(stIdx == -1) return "";
        return s.substr(stIdx, minLen);
    }
};
