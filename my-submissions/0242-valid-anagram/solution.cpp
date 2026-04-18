class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            if(m.count(s[i])) {
                m[s[i]]++;
            } else {
                m[s[i]] = 1;
            }
        }
        for(int i = 0; i < t.size(); i++) {
            if(m.count(t[i])) {
                if(m[t[i]] == 1) {
                    m.erase(t[i]);
                } else {
                    m[t[i]]--;
                }
            } else {
                return false;
            }
        }
        if(m.size() == 0) return true;
        return false;
    }
};
