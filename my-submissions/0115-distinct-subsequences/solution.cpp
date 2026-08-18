class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> prev(m + 1, 0), curr(m + 1, 0);

        prev[0] = 1;

        for(int i = 1; i <= n; i++) {
            fill(curr.begin(), curr.end(), 0);
            curr[0] = 1;
            for(int j = 1; j <= min(i, m); j++) {
                if(s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return curr[m];
    }
};
