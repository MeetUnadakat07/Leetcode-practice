class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(tokens[i]);
            } else {
                int n1, n2, ans;
                n1 = stoi(s.top());
                s.pop();
                n2 = stoi(s.top());
                s.pop();
                if(tokens[i] == "+") {
                    ans = n2 + n1;
                } else if(tokens[i] == "-") {
                    ans = n2 - n1;
                } else if(tokens[i] == "*") {
                    ans = n2 * n1;
                } else {
                    ans = n2 / n1;
                }
                s.push(to_string(ans));
            }
        }
        return stoi(s.top());
    }
};
