class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hrDeg = (hour % 12) * 30 + minutes * 0.5;
        double minDeg = minutes * 6;

        double deg = abs(hrDeg - minDeg);
        return min(deg, 360 - deg);
    }
};
