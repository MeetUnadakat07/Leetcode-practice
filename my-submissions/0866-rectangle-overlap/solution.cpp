class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int commWidthSt = max(rec1[0], rec2[0]);
        int commWidthEnd = min(rec1[2], rec2[2]);
        int commHeightSt = max(rec1[1], rec2[1]);
        int commHeightEnd = min(rec1[3], rec2[3]);

        int commonWidth = commWidthEnd - commWidthSt;
        int commonHeight = commHeightEnd - commHeightSt;

        return (commonWidth > 0 && commonHeight > 0);
    }
};
