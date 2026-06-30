class Solution {
public:
    int numberOfSubstrings(string s) {
        int st = 0, end = 0;
        int count = 0;
        int freq[3] = {0, 0, 0};

        while(end < s.size()) {
            freq[s[end] - 'a']++;

            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += s.size() - end;
                freq[s[st] - 'a']--;
                st++;
            }
            end++;
        }
        return count;
    }
};
