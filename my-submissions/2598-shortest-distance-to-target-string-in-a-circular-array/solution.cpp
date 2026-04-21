class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int direct = abs(i - startIndex);
                int circular = n - direct;
                int dist = min(direct, circular);
                minDist = min(minDist, dist);
            }
        }
        
        return (minDist == INT_MAX) ? -1 : minDist;
    }
};
