class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for (char ch : s) {
            if (ch == ')') {
                if (!st.empty()) {
                    char c = st.top();
                    if (c == '(') {
                        st.pop();
                    } else {
                        count++;
                    }
                } else {
                    st.push(ch);
                }
            } else {
                st.push(ch);
            }
        }
        return count + st.size();
    }
};
