class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        long long place = 1;

        while(n > 0) {
            int rem = n % 10;
            sum += rem;

            if(rem != 0) {
                num += rem * place;
                place *= 10;
            }

            n /= 10;
        }

        return sum * num;
    }
};
