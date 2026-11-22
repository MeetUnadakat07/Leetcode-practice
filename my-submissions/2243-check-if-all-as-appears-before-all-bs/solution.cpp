class Solution {
public:
    bool checkString(string s) {
        int bIdx = s.size();
        for(int i = 0; i < s.size(); i++) {
            if(bIdx == s.size() && s[i] == 'b') {
                bIdx = i;
            } else {
                if(s[i] == 'a' && i > bIdx) return false;
            }
        }
        return true;
    }
};
