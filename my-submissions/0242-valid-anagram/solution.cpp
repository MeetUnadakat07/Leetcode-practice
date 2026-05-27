class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int>m;
        for(int i = 0; i < s.size(); i++) {
            if(m.count(s[i]) == 0) {
                m[s[i]] = 1;
            } else {
                m[s[i]]++;
            }
        }
        for(int i = 0; i < t.size(); i++) {
            m[t[i]]--;
            if(m[t[i]] < 0) return false;
        }
        for(pair<char, int> p : m) {
            if(p.second != 0) return false;
        }
        return true;
    }
};
