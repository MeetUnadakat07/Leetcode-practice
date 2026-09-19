class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(x2, xCenter));
        int closestY = max(y1, min(y2, yCenter));

        int dx = closestX - xCenter;
        int dy = closestY - yCenter;

        return dx * dx + dy * dy <= radius * radius;
    }
};
