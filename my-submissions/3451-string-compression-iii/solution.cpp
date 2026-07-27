class Solution {
public:
    string compressedString(string word) {
        char curr = word[0];
        int count = 1;
        string ans = "";
        for(int i = 1; i < word.size(); i++) {
            if(curr == word[i]) {
                if(count == 9) {
                    ans += "9";
                    ans += curr;
                    count = 1;
                } else {
                    count++;
                }
            } else {
                ans += to_string(count);
                ans += curr;
                curr = word[i];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += curr;
        return ans;
    }
};
