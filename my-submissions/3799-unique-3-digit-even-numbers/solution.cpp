class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int d : digits) {
            freq[d]++;
        }
        int ans = 0;

        // first digit cannot be 0
        for(int first = 1; first <= 9; first++) {
            if(freq[first] == 0) continue;

            freq[first]--;
            // second digit can be any number
            for(int second = 0; second <= 9; second++) {
                if(freq[second] == 0) continue;

                freq[second]--;
                // last digit needs to be even
                for(int third = 0; third <= 8; third += 2) {
                    if(freq[third] > 0) {
                        ans++;
                    }
                }
                freq[second]++;
            }
            freq[first]++;
        }
        return ans;
    }
};
