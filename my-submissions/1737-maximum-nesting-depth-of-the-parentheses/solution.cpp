class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxCount = 0;
        for(char ch : s) {
            if(ch == '(') {
                count++;
            } else if(ch == ')') {
                count--;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
