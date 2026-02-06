class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;          // stack to store numbers
        stack<string> strs;       // stack to store strings
        string cur = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // build multi-digit number
            }
            else if (c == '[') {
                nums.push(num);       // push the number
                strs.push(cur);       // push current string
                num = 0;
                cur = "";
            }
            else if (c == ']') {
                int k = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                // repeat current string k times
                string tmp = "";
                while (k--) tmp += cur;

                cur = prev + tmp;     // combine with previous string
            }
            else {
                cur += c;             // normal character
            }
        }

        return cur;
    }
};

