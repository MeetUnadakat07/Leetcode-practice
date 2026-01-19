class Solution {
public:

vector<string> keypad = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

    void keypadCombinations(string digits, int ele, string ans, vector<string> &res) {
        if(ele == digits.size()) {
            res.push_back(ans);
            return;
        }
        string letters = keypad[digits[ele] - '0'];

        for(char ch : letters) {
            keypadCombinations(digits, ele + 1, ans + ch, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        keypadCombinations(digits, 0, "", res);
        return res;
    }
};
