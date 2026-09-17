class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int st = 0, maxFruits = 0, distinctTypes = 0;
        int n = fruits.size();
        vector<int> freq(n, 0);
        for(int end = 0; end < n; end++) {
            if(freq[fruits[end]] == 0) {
                distinctTypes++;
            }
            freq[fruits[end]]++;

            if(distinctTypes > 2) {
                freq[fruits[st]]--;
                if(freq[fruits[st]] == 0) {
                    distinctTypes--;
                }
                st++;
            }
            maxFruits = max(maxFruits, end - st + 1);
        }
        return maxFruits;
    }
};
