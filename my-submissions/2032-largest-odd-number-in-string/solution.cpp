class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--) {
            int n = num[i] - '0';
            if(n % 2) return num;
            num.pop_back();
        }
        return "";
    }
};
