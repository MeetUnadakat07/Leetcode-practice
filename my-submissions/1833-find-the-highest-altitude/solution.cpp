class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, maxAlt = 0;
        for(int i : gain) {
            curr = curr + i;
            maxAlt = max(curr, maxAlt);
        }
        return maxAlt;
    }
};
