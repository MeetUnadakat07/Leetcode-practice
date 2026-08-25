class Solution {
public:
    int minInsertions(string str) {
        stack<char> s;
        int n = str.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(str[i] == '(') {
                s.push(str[i]);
            } else {
                if(i + 1 < n && str[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }

                if(!s.empty()) {
                    s.pop();
                } else {
                    ans++;
                }
            }
        }

        ans += (s.size() * 2);
        return ans;
    }
};
