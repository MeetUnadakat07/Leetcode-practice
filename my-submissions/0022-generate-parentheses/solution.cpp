class Solution {
public:
    void backtrack(vector<string> &ans, int n, int open, int close, string s) {
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if(open < n) {
            backtrack(ans, n, open + 1, close, s + "(");
        }

        if(close < open) {
            backtrack(ans, n, open, close + 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack(ans, n, 0, 0, "");
        return ans;
    }
};
