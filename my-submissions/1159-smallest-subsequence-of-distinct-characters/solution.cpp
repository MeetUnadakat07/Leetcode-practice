class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastOcc(26);

        for(int i = 0; i < s.size(); i++) {
            lastOcc[s[i] - 'a'] = i;
        }

        string ans = "";
        unordered_set<char> st;

        for(int i = 0; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) {
                continue;
            }

            while(!ans.empty() && ans.back() > s[i] && lastOcc[ans.back() - 'a'] > i) {
                st.erase(ans.back());
                ans.pop_back();
            }

            ans += s[i];
            st.insert(s[i]);
        }

        return ans;
    }
};
