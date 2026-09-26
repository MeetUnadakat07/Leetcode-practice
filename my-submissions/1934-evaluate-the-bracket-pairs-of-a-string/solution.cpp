class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string word = "", ans = "";
        unordered_map<string, string> m;
        for(int i = 0; i < knowledge.size(); i++) {
            m[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                i++;
                while(s[i] != ')') {
                    word += s[i];
                    i++;
                }
                if(m[word] == "") {
                    ans += "?";
                } else {
                    ans += m[word];
                }
                word = "";
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
