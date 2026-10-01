class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch == ')') {
                if(!st.empty()) {
                    char c = st.top();
                    st.pop();
                    if(c != '(') {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if(ch == ']') {
                if(!st.empty()) {
                    char c = st.top();
                    st.pop();
                    if(c != '[') {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if(ch == '}') {
                if(!st.empty()) {
                    char c = st.top();
                    st.pop();
                    if(c != '{') {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
