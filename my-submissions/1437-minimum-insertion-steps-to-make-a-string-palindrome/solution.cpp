class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // taking the length of longest palindromic subsequence
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        
        return n - curr[n];
    }
};
