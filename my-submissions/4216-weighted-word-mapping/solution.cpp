class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s, ans;
        for(int i = 0; i < words.size(); i++) {
            s = words[i];
            char ch;
            int n = 0;
            for(int j = 0; j < s.size(); j++) {
                ch = s[j];
                n += weights[s[j] - 'a'];
            }
            n = n % 26;
            ch = 'z' - n;
            ans += ch;
        }
        return ans;
    }
};
