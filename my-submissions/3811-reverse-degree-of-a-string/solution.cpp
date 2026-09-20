class Solution {
public:
    int reverseDegree(string s) {
        int a = 26;
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            sum += ((i + 1) * (a - (s[i] - 'a')));
        }
        return sum;
    }
};
