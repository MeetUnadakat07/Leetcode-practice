class Solution {
public:
    int numberOfSubstrings(string s) {
        int st = 0, count = 0;
        int n = s.size();
        int freq[] = {0, 0, 0};

        for(int end = 0; end < n; end++) {
            freq[s[end] - 'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += n - end;
                freq[s[st] - 'a']--;
                st++;
            }
        }
        return count;
    }
};
