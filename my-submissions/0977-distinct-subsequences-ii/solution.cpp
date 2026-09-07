class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> end(26, 0);
        int MOD = 1e9 + 7;
        int total = 0;
        for(int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            int oldTotal = total;
            int newSubseq = (oldTotal + 1 - end[idx] + MOD) % MOD;
            total = (total + newSubseq) % MOD;
            end[idx] = (end[idx] + newSubseq) % MOD;
        }
        return total;
    }
};
