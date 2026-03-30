class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        if(deck.size() == 1) return false;
        vector<int> freq(10000, 0);
        for (int i = 0; i < deck.size(); i++) {
            freq[deck[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] > 0) {
                if(ans == 0) {
                    ans = freq[i];
                } else {
                    ans = gcd(ans, freq[i]);
                }
            }
        }
        return ans >= 2;
    }
};
