class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        string ans = "";
        string unique = "";

        int i = 0;
        while(i < 26) {
            if(freq[i] == 0) {
                i++;
            } else if(freq[i] == 1) {
                unique = (i + 'a');
                i++;
            } else {
                ans += (i + 'a');
                freq[i] -= 2;
            }
        }
        string rev = string(ans.rbegin(), ans.rend());
        return (ans + unique + rev);
    }
};
