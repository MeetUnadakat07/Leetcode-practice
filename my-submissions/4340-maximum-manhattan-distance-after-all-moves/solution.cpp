class Solution {
public:
    int maxDistance(string moves) {
        int hdist = 0, vdist = 0;
        int totalDist = 0;
        for(char ch : moves) {
            if(ch == 'U') {
                vdist += 1;
            } else if(ch == 'D') {
                vdist -= 1;
            } else if(ch == 'L') {
                hdist -= 1;
            } else if(ch == 'R') {
                hdist += 1;
            } else {
                totalDist++;
            }
        }
        return totalDist + abs(vdist) + abs(hdist);
    }
};
