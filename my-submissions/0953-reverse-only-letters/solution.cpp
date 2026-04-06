class Solution {
public:
    string reverseOnlyLetters(string s) {
        int st = 0, end = s.size() - 1;
        while(st < end) {
            if(!isalpha(s[st])) {
                st++;
            } else if(!isalpha(s[end])) {
                end--;
            } else {
                swap(s[st], s[end]);
                st++;
                end--;
            }
        }
        return s;
    }
};
