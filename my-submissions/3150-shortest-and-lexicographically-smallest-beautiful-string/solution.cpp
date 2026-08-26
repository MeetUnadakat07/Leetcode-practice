class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int st = 0;
        int cnt1 = 0;
        int maxLen = INT_MAX;
        string ans = "";

        for(int end = 0; end < s.size(); end++) {
            if(s[end] == '1') {
                cnt1++;
            }
            while(st <= end && cnt1 == k) {
                string curr = s.substr(st, (end - st + 1));

                if(ans.empty() || curr.size() < ans.size() || curr.size() == ans.size() && curr < ans) {
                    ans = curr;
                }
                if(s[st] == '1') {
                    cnt1--;
                }
                st++;
            }
        }
        return ans;
    }
};
