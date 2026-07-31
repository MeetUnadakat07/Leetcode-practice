class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for(char ch : word) {
            m[ch]++;
        }

        vector<pair<char, int>> vec(m.begin(), m.end());

        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });

        int count = 0;
        int mul = 1;
        int ans = 0;

        for(auto p : vec) {
            if(count >= 24) {
                mul = 4;
            } else if(count >= 16) {
                mul = 3;
            } else if(count >= 8) {
                mul = 2;
            } 
            ans += p.second * mul;
            count++;
        }
        return ans;
    }
};
