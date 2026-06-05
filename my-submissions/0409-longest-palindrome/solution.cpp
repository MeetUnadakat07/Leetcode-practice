class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }
        int n = 0;
        bool hasOdd = false;

        for(auto p : freq) {
            n += (p.second / 2) * 2;

            if(p.second % 2) {
                hasOdd = true;
            }
        }
        return hasOdd ? n + 1 : n;
    }
};
