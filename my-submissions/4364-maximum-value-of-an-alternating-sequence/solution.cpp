class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long noOfPeaks = n / 2;

        return s + m + (noOfPeaks - 1) * (m - 1);
    }
};
