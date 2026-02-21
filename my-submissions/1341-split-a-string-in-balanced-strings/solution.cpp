class Solution {
public:
    int balancedStringSplit(string s) {
        int countL = 0;
        int countR = 0;
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(countR == countL) {
                count++;
            }
            if(ch == 'L') {
                countL++;
            } else {
                countR++;
            }
        }
        return count;
    }
};
