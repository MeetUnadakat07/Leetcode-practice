class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOfOdd = pow(n, 2);
        int sumOfEven = n * (n + 1);
        return gcd(sumOfOdd, sumOfEven);
    }
};
