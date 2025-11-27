class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1 == word2) return true;
        if(word1.length() != word2.length()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i = 0; i < word1.length(); i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];
            freq1[ch1 - 'a']++;
            freq2[ch2 - 'a']++;
        }

        // check if a character is present in only one string
        for(int i = 0; i < 26; i++) {
            if((freq1[i] == 0 && freq2[i] > 0) || (freq1[i] > 0 && freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        if(freq1 == freq2) {
            return true;
        } else {
            return false;
        }
    }
};
