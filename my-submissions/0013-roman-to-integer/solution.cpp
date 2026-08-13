class Solution {
public:
    int romanToInt(string num) {
        int n = num.size();
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;
        int prev = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curr = m[num[i]];
            if (m[num[i]] >= prev) {
                ans += curr;
            } else {
                ans -= curr;
            }
            prev = curr;
        }
        return ans;
    }
};
