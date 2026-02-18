class Solution {
public:
    int minimumChairs(string s) {
        int maxChairs = 0;
        int chairs = 0;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == 'E') {
                chairs++;
            } else {
                chairs--;
            }
            maxChairs = max(maxChairs, chairs);
        }
        return maxChairs;
    }
};
