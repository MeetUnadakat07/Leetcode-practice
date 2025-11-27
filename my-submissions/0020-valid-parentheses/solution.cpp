class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false;
        vector<char> v;
        for(int i = 0; i < s.length(); i++) {
            // char ch = s[i];
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                v.push_back(s[i]);
            } else {
                if(v.size() == 0) {
                    return false;
                } else {
                    if(s[i] == ')' && v.back() == '(') {
                        v.pop_back();
                    } else if(s[i] == ']' && v.back() == '[') {
                        v.pop_back();
                    } else if(s[i] == '}' && v.back() == '{') {
                        v.pop_back();
                    } else {
                        return false;
                    }
                }
            }
        }
        if(v.size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};
