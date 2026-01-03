class Solution {
public:
    int divide(int dividend, int divisor) {

        // 1. Handle the one overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // 2. Determine the sign
        bool positive = (dividend > 0) == (divisor > 0);

        // 3. Work with long long to avoid overflow
        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long result = 0;

        // 4. Binary division using doubling
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        // 5. Apply sign safely while still long long
        if (!positive) result = -result;

        // 6. Return as int (safe now)
        return (int)result;
    }
};

