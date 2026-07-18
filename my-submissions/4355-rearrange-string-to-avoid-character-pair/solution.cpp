class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int> m;
        string ans = "";
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        if(m[x] == 0 || m[y] == 0) return s;

        int xCount = m[x];
        int yCount = m[y];

        ans = ans.append(yCount, y);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != y) {
                ans += s[i];
            }
        }
        return ans;
    }
};
