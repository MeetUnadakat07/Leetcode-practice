class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lastLower;
        unordered_map<char, int> firstUpper;

        for (int i = 0; i < word.size(); i++) {
            if (islower(word[i])) {
                lastLower[word[i]] = i;     // keep updating
            } else {
                if (!firstUpper.count(word[i]))
                    firstUpper[word[i]] = i; // first occurrence only
            }
        }

        int ans = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            char up = toupper(c);

            if (lastLower.count(c) &&
                firstUpper.count(up) &&
                lastLower[c] < firstUpper[up]) {
                ans++;
            }
        }

        return ans;
    }
};
